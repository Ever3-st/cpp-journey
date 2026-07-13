#include <iostream>
#include <string>

class LogPacket {
private:
    std::string m_timestamp;
    std::string m_level;
    std::string m_message;

public:
    LogPacket(std::string time, std::string lvl, std::string msg) {
        m_timestamp = time;
        m_level = lvl;
        m_message = msg;
        std::cout << "[CONSTRUCTOR] New LogPacket initialized at memory address: " << this << "\n";
    }

    void printDiagnostic() {
        std::cout << "  [" << m_level << "] occurred at " << m_timestamp 
                  << " -> Event: " << m_message << "\n";
    }

    void overrideMessage(std::string newMessage) {
        if (newMessage.empty()) {
            std::cout << "  [REJECTED] Cannot overwrite log with empty message!\n";
            return;
        }
        m_message = newMessage;
    }
};

int main() {
    std::cout << "[SYSTEM] Initializing Object-Oriented Structures...\n";
    std::cout << "--------------------------------------------------\n";

    LogPacket packetA("10:00:02", "INFO", "Boot sequence completed.");
    LogPacket packetB("10:15:44", "CRITICAL", "Core temperature warning.");

    std::cout << "\n[EXECUTION] Dispatching member logic:\n";
    packetA.printDiagnostic();
    packetB.printDiagnostic();
    
    std::cout << "--------------------------------------------------\n";
    std::cout << "[SECURITY] Attempting data modifications via public interface...\n";

    packetB.overrideMessage("Automated cooling matrix deployed.");
    packetB.printDiagnostic();

    std::cout << "--------------------------------------------------\n";
    return 0;
}
