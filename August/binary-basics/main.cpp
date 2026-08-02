#include <iostream>
#include <cstdint>
#include <bitset>

int main()
{
    std::cout << "=======================================================\n";
    std::cout << "        DAY 1: FIXED-WIDTH & BINARY INSPECTION        \n";
    std::cout << "=======================================================\n";
    
    uint64_t registerBank = 0b10101010101010101010101010101010101010101010101010101010101010ULL;
    
    std::cout << " Size of registerBank : " << sizeof(registerBank) << " bytes ("
              << sizeof(registerBank) * 8 << " bits)\n";
              
    std::cout << " Decimal Value        : " << registerBank << "\n";
    std::cout << " Hexadecimal Representation : 0x" << std::hex << registerBank << std::dec << "\n";
    std::cout << " Raw Binary (bitset)  : " << std::bitset<64>(registerBank) << "\n";
    
    std::cout << "========================================================\n";
    
    uint64_t bitShiftTest = 1ULL << 40;
    std::cout << " Bit 40 Set via 1ULL  : " << std::bitset<64>(bitShiftTest) << "\n";
    
    return 0;
}
