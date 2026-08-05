#include <iostream>
#include <cstdint>
#include <bitset>

constexpr uint64_t FLAG_ENGINE_ON     = 1ULL << 0; // Bit 0
constexpr uint64_t POWER_LEVEL_SHIFT  = 4;         // Starts at Bit 4
constexpr uint64_t POWER_LEVEL_MASK   = 0xF0ULL;   // Bits 4-7 active (0b11110000)

int main() {
    std::cout << "========================================================\n";
    std::cout << "       DAY 04: BIT SHIFTING (<< and >>) & BITFIELDS     \n";
    std::cout << "========================================================\n";

    uint64_t systemRegister = 0ULL;
    systemRegister |= FLAG_ENGINE_ON;

    std::cout << "[STEP 1] Engine Turned ON:\n";
    std::cout << " Register Binary : " << std::bitset<16>(systemRegister) << "\n\n";

    uint64_t targetPower = 11ULL; // Target value: 11 (Binary: 1011)

    std::cout << "--- 2. Setting Engine Power Level to " << targetPower << " ---\n";

    uint64_t shiftedPower = (targetPower & 0xFULL) << POWER_LEVEL_SHIFT;

    systemRegister = (systemRegister & ~POWER_LEVEL_MASK) | shiftedPower;

    std::cout << " Register Binary : " << std::bitset<16>(systemRegister) << "\n";
    std::cout << " Notice bits 4-7 : 1011 (Decimal 11) sitting at Bit 4 position!\n\n";
    std::cout << "--- 3. Extracting Power Level from Register ---\n";

    uint64_t extractedPower = (systemRegister >> POWER_LEVEL_SHIFT) & 0xFULL;

    std::cout << " Extracted Power Value : " << extractedPower << " / 15\n";

    std::cout << "========================================================\n";
    return 0;
}
