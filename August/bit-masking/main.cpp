#include <iostream>
#include <cstdint>
#include <bitset>

constexpr uint64_t createMask(uint8_t width) {
    return (width >= 64) ? ~0ULL : ((1ULL << width) - 1ULL);
}

constexpr uint64_t createFieldMask(uint8_t width, uint8_t shift) {
    return createMask(width) << shift;
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "       DAY 06: DYNAMIC BIT MASK GENERATION              \n";
    std::cout << "========================================================\n";

    std::cout << "--- 1. Generating Unshifted Masks ---\n";
    std::cout << " 3-bit Mask (Width 3) : " << std::bitset<16>(createMask(3)) 
              << " (Hex: 0x" << std::hex << createMask(3) << std::dec << ")\n";
    std::cout << " 6-bit Mask (Width 6) : " << std::bitset<16>(createMask(6)) 
              << " (Hex: 0x" << std::hex << createMask(6) << std::dec << ")\n";
    std::cout << " 8-bit Mask (Width 8) : " << std::bitset<16>(createMask(8)) 
              << " (Hex: 0x" << std::hex << createMask(8) << std::dec << ")\n\n";

    constexpr uint8_t FIELD_WIDTH = 5;
    constexpr uint8_t FIELD_SHIFT = 6;
    constexpr uint64_t DYNAMIC_FIELD_MASK = createFieldMask(FIELD_WIDTH, FIELD_SHIFT);

    std::cout << "--- 2. Shifted Field Mask (Width 5 at Shift 6) ---\n";
    std::cout << " Field Mask Binary : " << std::bitset<16>(DYNAMIC_FIELD_MASK) << "\n\n";

    uint64_t hardwareRegister = 0ULL;
    uint64_t sensorValue = 27ULL;

    std::cout << "--- 3. Injecting Value (" << sensorValue << ") into Dynamic Bitfield ---\n";

    hardwareRegister = (hardwareRegister & ~DYNAMIC_FIELD_MASK) 
                     | ((sensorValue & createMask(FIELD_WIDTH)) << FIELD_SHIFT);

    std::cout << " Register Binary   : " << std::bitset<16>(hardwareRegister) << "\n";

    uint64_t extractedValue = (hardwareRegister >> FIELD_SHIFT) & createMask(FIELD_WIDTH);
    std::cout << " Extracted Value   : " << extractedValue << " / 31\n";

    std::cout << "========================================================\n";
    return 0;
}
