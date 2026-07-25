#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <memory>

enum class ParserState {
    INITIALIZING,
    EXECUTION_RUNNING,
    CRITICAL_EXCEPTION,
    HALTED
};

class CoreDumpParser {
private:
    ParserState m_currentState;
    std::unique_ptr<std::string> m_monolithicBuffer;
    std::string_view m_workingWindow;
    
    size_t m_linesScanned;
    size_t m_faultCount;
    std::string_view m_lastFaultAddress;
    
    std::string getStateName(ParserState state) const;
    bool transitionTo(ParserState newState);
    
    std::string_view extractHexAddress(std::string_view line) const;

public:
    CoreDumpParser();
    ~CoreDumpParser();

    CoreDumpParser(const CoreDumpParser&) = delete;
    CoreDumpParser& operator=(const CoreDumpParser&) = delete;

    bool loadCoreDump(const std::string& rawLogData);
    void runDiagnosticLoop();
    
    void printTelemetryReport() const;
    ParserState getCurrentState() const;
};
