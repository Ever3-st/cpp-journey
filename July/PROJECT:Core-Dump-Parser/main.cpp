#include "parser.hpp"
#include <iostream>

int main() {
    std::cout << "========================================================\n";
    std::cout << "    STANDALONE CORE-DUMP LOGIC PARSER (PROJECT 1)    \n";
    std::cout << "========================================================\n";

    std::string mockCrashDump = 
        "[INFO] System boot completed at 0x7FFF0001\n"
        "[INFO] Thread 0x01 initialized execution pool.\n"
        "[DEBUG] Register dump: RAX=0x00000000 RBX=0x00FF8812\n"
        "[CRITICAL] Memory access violation at address 0x00000000 (Null Pointer)\n"
        "[DEBUG] Attempting stack unwinding...\n"
        "[FATAL] Kernel stack corrupted. Execution permanently halted.\n"
        "[INFO] This line should never be processed due to HALTED wall.\n";

    CoreDumpParser parser;

    if (parser.loadCoreDump(mockCrashDump)) {
        parser.runDiagnosticLoop();
    }

    std::cout << "========================================================\n";
    std::cout << "[SYSTEM] Terminal execution complete.\n";

    return 0;
}
