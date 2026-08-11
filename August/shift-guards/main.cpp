#include <iostream>
#include <cstdint>
#include <bitset>

constexpr uint64_t safeLeftShift(uint64_t val, uint8_t shift) {
    if (shift >= 64) return 0ULL;
    return val << shift;
}

constexpr uint64_t safeRightShift(uint64_t val, uint8_t shift) {
    if (shift >= 64) return 0ULL;
    return val >> shift;
}

constexpr uint64_t safeCreateMask(uint8_t width) {
    if (width >= 64) return ~0ULL;
    return (1ULL << width) - 1ULL;
}

int main() {
    std::cout << "=====================================================\n";
    std::cout << "     DAY 08: SHIFT OVERFLOW & UNDEFINED BEHAVIOR     \n";
    std::cout << "=====================================================\n";
    
    uint64_t baseValue  = 0b1111ULL;
    
    std::cout << "--- 1. Valid Left Shift by 8 Bits ---\n";
    uint64_t validShift = safeLeftShift(baseValue, 8);
    std::cout << " Result Binary : " << std::bitset<64>(validShift) << "\n\n";
    
    std::cout << "--- 2. Out-of-Bounds Left Shift by 64 Bits ---\n";
    uint64_t invalidShift = safeLeftShift(baseValue, 64);
    std::cout << " Result Binary: " << std::bitset<64>(invalidShift) << " (Safely caught as 0)\n\n";
    
    std::cout << "--- 3. Generating Full 64-Bit Mask ---\n";
    uint64_t fullMask = safeCreateMask(64);
    std::cout << " 64-Bit Mask   : " << std::bitset<64>(fullMask) << "\n";
    std::cout << " Hex Output    : 0x" << std::hex << fullMask << std::dec << "\n";
    
    std::cout << "=====================================================\n";
    return 0;
}
