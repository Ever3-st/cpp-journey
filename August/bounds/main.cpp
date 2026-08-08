#include <iostream>
#include <cstdint>
#include <bitset>

constexpr uint64_t createMask(uint8_t width) {
    return (width >= 64) ? ~0ULL : ((1ULL << width) - 1ULL);
}

bool tryPackField(uint64_t& targetRegister, uint64_t rawValue, uint8_t width, uint8_t shift) {
    uint64_t maxAllowedValue = createMask(width);

    if (rawValue > maxAllowedValue) {
        std::cout << " [ERROR] Value " << rawValue << " exceeds max field capacity of " 
                  << maxAllowedValue << " (" << (int)width << " bits)! Write rejected.\n";
        return false;
    }

    uint64_t fieldMask = maxAllowedValue << shift;
    targetRegister = (targetRegister & ~fieldMask) | ((rawValue & maxAllowedValue) << shift);
    return true;
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "     DAY 07: BITFIELD BOUNDS VALIDATION & SAFETY        \n";
    std::cout << "========================================================\n";

    uint64_t controlRegister = 0ULL;

    constexpr uint8_t FIELD_WIDTH = 4;
    constexpr uint8_t FIELD_SHIFT = 4;

    std::cout << "Target Register Field: 4 bits wide at Bit 4 (Max value: 15)\n\n";

    std::cout << "--- Test 1: Writing Valid Value (12) ---\n";
    if (tryPackField(controlRegister, 12ULL, FIELD_WIDTH, FIELD_SHIFT)) {
        std::cout << " [SUCCESS] Register Binary: " << std::bitset<16>(controlRegister) << "\n\n";
    }

    std::cout << "--- Test 2: Attempting Overflow Write (19) ---\n";
    if (!tryPackField(controlRegister, 19ULL, FIELD_WIDTH, FIELD_SHIFT)) {
        std::cout << " [SAFEGUARD] Register Binary Unchanged: " 
                  << std::bitset<16>(controlRegister) << "\n\n";
    }

    uint64_t currentVal = (controlRegister >> FIELD_SHIFT) & createMask(FIELD_WIDTH);
    std::cout << "Final Extracted Value: " << currentVal << " / 15\n";

    std::cout << "========================================================\n";
    return 0;
}
