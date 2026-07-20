#include <iostream>
#include <string>

class SystemSnapshot {
private:
    int* m_registerLogs;
    size_t m_logCount;

public:
   SystemSnapshot(size_t logCount) : m_logCount(logCount) {
        m_registerLogs = new int[m_logCount];
        std::cout << "[SYS_INIT] Core system snapshot captured. Allocated heap space at: " 
                  << m_registerLogs << "\n";
    }

    ~SystemSnapshot() {
        delete[] m_registerLogs;
        std::cout << "[SYS_CLEANUP] Snapshot drop out of scope. Heap memory safely vaporized.\n";
    }

    SystemSnapshot(const SystemSnapshot& other) = delete;
    SystemSnapshot& operator=(const SystemSnapshot& other) = delete;
    
    void logStatus() const {
        std::cout << "  Snapshot integrity operational. Processing " << m_logCount << " fields.\n";
    }
};

void analyzeSnapshot(const SystemSnapshot& snapshot) {
    snapshot.logStatus();
}

int main() {
    std::cout << "[START] Initializing Copy-Safe Architecture Practice...\n";
    std::cout << "--------------------------------------------------\n";

    SystemSnapshot primarySnapshot(150);
    primarySnapshot.logStatus();

    std::cout << "\n[TEST] Passing object via safe const reference:\n";
    analyzeSnapshot(primarySnapshot); // Works perfectly! Zero copies made.

    std::cout << "--------------------------------------------------\n";
    std::cout << "[COMPILER WALL TESTING ZONE]\n";

    std::cout << "  [SAFE] Copy prevention locks detected by static analysis.\n";
    std::cout << "--------------------------------------------------\n";
    
    return 0;
}
