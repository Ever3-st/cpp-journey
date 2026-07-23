#include "parser.hpp"
#include <iostream>
#include <sstream>

CoreDumpParser::CoreDumpParser() 
    : m_currentState(ParserState::INITIALIZING),
      m_monolithicBuffer(std::make_unique<std::string>()),
      m_workingWindow() {
    std::cout << "[PARSER_INIT] FSM active. Allocated heap buffer wrapper.\n";
}

CoreDumpParser::~CoreDumpParser() {
    std::cout << "[PARSER_SHUTDOWN] RAII cleanup: Memory buffer automatically reclaimed.\n";
}

std::string CoreDumpParser::getStateName(ParserState state) const {
    switch (state) {
        case ParserState::INITIALIZING:       return "INITIALIZING";
        case ParserState::EXECUTION_RUNNING:  return "EXECUTION_RUNNING";
        case ParserState::CRITICAL_EXCEPTION: return "CRITICAL_EXCEPTION";
        case ParserState::HALTED:             return "HALTED";
    }
    return "UNKNOWN";
}

bool CoreDumpParser::transitionTo(ParserState newState) {
    if (m_currentState == ParserState::HALTED) {
        std::cout << "  [FSM_BLOCKED] Transition to " << getStateName(newState) 
                  << " rejected -> Engine permanently HALTED.\n";
        return false;
    }

    std::cout << "  [FSM_TRANSITION] " << getStateName(m_currentState) 
              << " ---> " << getStateName(newState) << "\n";
    m_currentState = newState;
    return true;
}

bool CoreDumpParser::loadCoreDump(const std::string& rawLogData) {
    if (m_currentState == ParserState::HALTED) {
        return false;
    }

    *m_monolithicBuffer = rawLogData;
    m_workingWindow = *m_monolithicBuffer;

    std::cout << "[DATA_LOADED] Monolithic buffer populated (" 
              << m_workingWindow.size() << " bytes loaded).\n";

    return transitionTo(ParserState::EXECUTION_RUNNING);
}

void CoreDumpParser::runDiagnosticLoop() {
    if (m_currentState != ParserState::EXECUTION_RUNNING) {
        std::cout << "[ERROR] Cannot execute diagnostic loop outside EXECUTION_RUNNING state.\n";
        return;
    }

    std::cout << "[SCAN_START] Beginning zero-copy string_view inspection loop...\n";

    std::string_view streamView = m_workingWindow;
    size_t lineNum = 1;

    size_t startPos = 0;
    while (startPos < streamView.size()) {
        size_t endPos = streamView.find('\n', startPos);
        if (endPos == std::string_view::npos) {
            endPos = streamView.size();
        }

        std::string_view currentLine = streamView.substr(startPos, endPos - startPos);

        if (currentLine.find("CRITICAL") != std::string_view::npos) {
            std::cout << "  [LINE " << lineNum << "] Fault detected: " << currentLine << "\n";
            transitionTo(ParserState::CRITICAL_EXCEPTION);
        } else if (currentLine.find("FATAL") != std::string_view::npos) {
            std::cout << "  [LINE " << lineNum << "] Unrecoverable state: " << currentLine << "\n";
            transitionTo(ParserState::HALTED);
            break;
        }

        startPos = endPos + 1;
        lineNum++;
    }

    std::cout << "[SCAN_COMPLETE] Final FSM State: " << getStateName(m_currentState) << "\n";
}

ParserState CoreDumpParser::getCurrentState() const {
    return m_currentState;
}
