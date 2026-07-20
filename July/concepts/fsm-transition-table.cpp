#include <iostream>
#include <string>

enum class ParserState {
    INITIALIZING,
    EXECUTION_RUNNING,
    CRITICAL_EXCEPTION,
    HALTED
};

class ParserStateEngine {
private:
    ParserState m_currentState;

    std::string getStateName(ParserState state) const {
        switch (state) {
            case ParserState::INITIALIZING:       return "INITIALIZING";
            case ParserState::EXECUTION_RUNNING:  return "EXECUTION_RUNNING";
            case ParserState::CRITICAL_EXCEPTION: return "CRITICAL_EXCEPTION";
            case ParserState::HALTED:             return "HALTED";
        }
        return "UNKNOWN";
    }

public:
    ParserStateEngine() : m_currentState(ParserState::INITIALIZING) {}

    void printCurrentState() const {
        std::cout << "[STATUS] Engine State: " << getStateName(m_currentState) << "\n";
    }

    void transitionTo(ParserState newState) {
        // Defensive Rule: Once HALTED, the system can never change states again
        if (m_currentState == ParserState::HALTED) {
            std::cout << "[REJECTED] Cannot transition to " << getStateName(newState) 
                      << " -> Engine is permanently HALTED.\n";
            return;
        }

        std::cout << "[TRANSITION] Shifting from " << getStateName(m_currentState) 
                  << " ---> " << getStateName(newState) << "\n";
        
        m_currentState = newState;
    }
};

int main() {
    std::cout << "[SYSTEM] Initializing Combined Day 19/20 State Machine Archetype...\n";
    std::cout << "--------------------------------------------------\n";

    ParserStateEngine engine;
    engine.printCurrentState();

    engine.transitionTo(ParserState::EXECUTION_RUNNING);
    engine.transitionTo(ParserState::CRITICAL_EXCEPTION);
    
    engine.transitionTo(ParserState::HALTED);
    engine.printCurrentState();

    std::cout << "--------------------------------------------------\n";
    std::cout << "[DEFENSE TEST] Attempting unauthorized state change after halt:\n";
    
    engine.transitionTo(ParserState::EXECUTION_RUNNING);

    std::cout << "--------------------------------------------------\n";
    return 0;
}
