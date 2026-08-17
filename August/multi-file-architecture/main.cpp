#include <iostream>
#include <bitset>
#include "BitPacker.hpp"

int main() {
    std::cout << "========================================================\n";
    std::cout << "     DAY 12: MULTI-FILE ARCHITECTURE (.hpp & .cpp)      \n";
    std::cout << "========================================================\n";

    BitPacker packer;

    packer.setField(FieldShift::Power,       FieldWidth::Power,       1ULL);
    packer.setField(FieldShift::FanSpeed,    FieldWidth::FanSpeed,    6ULL);
    packer.setField(FieldShift::Temperature, FieldWidth::Temperature, 150ULL);

    std::cout << " Raw Register Binary : " << std::bitset<16>(packer.getRaw()) << "\n";
    std::cout << " Extracted Fan Speed : " << packer.getField(FieldShift::FanSpeed, FieldWidth::FanSpeed) << " / 7\n";
    std::cout << " Extracted Temp      : " << packer.getField(FieldShift::Temperature, FieldWidth::Temperature) << " deg C\n";

    std::cout << "========================================================\n";
    return 0;
}
