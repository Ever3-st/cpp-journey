#include <iostream>
#include <cstdint>
#include <iomanip>

int main() {
    std::cout << "========================================================\n";
    std::cout << "     DAY 16: POINTERS AND MEMORY ADDRESSES              \n";
    std::cout << "========================================================\n\n";

    uint64_t controlRegister = 0xDEADBEEF12345678ULL;
    uint32_t systemStatus    = 100;
    uint64_t* regPtr   = &controlRegister;
    uint32_t* statusPtr = &systemStatus;

    std::cout << "--- 1. Variable Values & Memory Address Mapping ---\n";
    std::cout << " controlRegister Value : 0x" << std::hex << controlRegister << "\n";
    std::cout << " Memory Address (&)    : " << &controlRegister << "\n";
    std::cout << " Pointer Storage (ptr) : " << regPtr << "\n\n";

    std::cout << "--- 2. Direct Value Mutation via Dereference (*) ---\n";
    std::cout << " Original statusValue  : " << std::dec << systemStatus << "\n";
    
    *statusPtr = 250; 
    
    std::cout << " Updated statusValue   : " << systemStatus << " (Modified via *statusPtr!)\n\n";

    std::cout << "--- 3. Verifying Memory Alias Relationship ---\n";
    if (regPtr == &controlRegister) {
        std::cout << " [SUCCESS] regPtr successfully points to memory location of controlRegister.\n";
    }

    std::cout << "========================================================\n";
    return 0;
}
