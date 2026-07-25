#include "parser.hpp"
#include <iostream>
#include <sstream>

CoreDumpParser::CoreDumpParser() 
    : m_currentState(ParserState::INITIALIZING),
      m_monolithicBuffer(std::make_unique<std::string>()),
      m_workingWindow(),
      m_linesScanned(0),
      m_faultCount(0),
      m_lastFaultAddress("NONE") {
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

std::string_view CoreDumpParser::extractHexAddress(std::string_view line) const {
    size_t pos = line.find("0x");
    if (pos == std::string_view::npos) {
        return "NO_HEX_ADDR";
    }
    
    size_t endPos = pos + 2;
    while (endPos < line.size() && std::isxdigit(line[endPos])) {
        endPos++;
    }
    
    return line.substr(pos, endPos - pos);
}

bool CoreDumpParser::loadCoreDump(const std::string& rawLogData) {
    if (m_currentState == ParserState::HALTED) return false;

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
    m_linesScanned = 0;
    m_faultCount = 0;
    size_t startPos = 0;
    
    while (startPos < streamView.size()) {
        size_t endPos = streamView.find('\n', startPos);
        if (endPos == std::string_view::npos) {
            endPos = streamView.size();
        }

        std::string_view currentLine = streamView.substr(startPos, endPos - startPos);
        m_linesScanned++;
        
        if (currentLine.find("CRITICAL") != std::string_view::npos) {
            std::string_view hexToken = extractHexAddress(currentLine);
            m_faultCount++;
            m_lastFaultAddress = hexToken;
            
            std::cout << "  [LINE " << m_linesScanned << "] Fault detected at Address ["
                      << hexToken << "]: " << currentLine << "\n";
            transitionTo(ParserState::CRITICAL_EXCEPTION);
            
        } else if (currentLine.find("FATAL") != std::string_view::npos) {
            std::string_view hexToken = extractHexAddress(currentLine);
            m_faultCount++;
            m_lastFaultAddress = hexToken;
            
            std::cout << "  [LINE " << m_linesScanned << "] Fatal Fault Vector ["
                      << hexToken << "]: " << currentLine << "\n";
            transitionTo(ParserState::HALTED);
            break;
        }

        startPos = endPos + 1;
    }

    std::cout << "[SCAN_COMPLETE] Final FSM State: " << getStateName(m_currentState) << "\n";
}

void CoreDumpParser::printTelemetryReport() const {
    std::cout << "\n========================================================\n";
    std::cout << "               PARSER TELEMETRY SUMMARY                 \n";
    std::cout << "========================================================\n";
    std::cout << "  * Total Lines Scanned : " << m_linesScanned << "\n";
    std::cout << "  * Total Faults Found  : " << m_faultCount << "\n";
    std::cout << "  * Last Fault Address  : " << m_lastFaultAddress << "\n";
    std::cout << "  * Final FSM Engine    : " << getStateName(m_currentState) << "\n";
    std::cout << "========================================================\n\n";
}

ParserState CoreDumpParser::getCurrentState() const {
    return m_currentState;
}
