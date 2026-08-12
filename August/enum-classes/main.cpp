#include <iostream>
#include <cstdint>
#include <bitset>

enum class FieldShift : uint8_t {
    Power       = 0,
    FanSpeed    = 1,
    Temperature = 4 
};

enum class FieldWidth : uint8_t {
    Power       = 1,
    FanSpeed    = 3,
    Temperature = 8
};

class EnumBitRegister {
private:
    uint64_t m_register = 0ULL;

    constexpr uint64_t createMask(uint8_t width) const {
        return (width >= 64) ? ~0ULL : ((1ULL << width) - 1ULL);
    }

public:
    EnumBitRegister() = default;

    bool setField(FieldShift fieldShift, FieldWidth fieldWidth, uint64_t value) {
        uint8_t shift = static_cast<uint8_t>(fieldShift);
        uint8_t width = static_cast<uint8_t>(fieldWidth);

        if (shift >= 64 || width == 0) return false;

        uint64_t maxVal = createMask(width);
        if (value > maxVal) {
            std::cout << " [REJECTED] Value " << value << " exceeds max field limit " 
                      << maxVal << " (" << (int)width << " bits)\n";
            return false;
        }

        uint64_t fieldMask = maxVal << shift;
        m_register = (m_register & ~fieldMask) | ((value & maxVal) << shift);
        return true;
    }

    uint64_t getField(FieldShift fieldShift, FieldWidth fieldWidth) const {
        uint8_t shift = static_cast<uint8_t>(fieldShift);
        uint8_t width = static_cast<uint8_t>(fieldWidth);

        if (shift >= 64 || width == 0) return 0ULL;
        return (m_register >> shift) & createMask(width);
    }

    uint64_t getRaw() const { return m_register; }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << "     DAY 11: TYPE-SAFE ENUM CLASS BIT-REGISTERS         \n";
    std::cout << "========================================================\n";

    EnumBitRegister reg;

    std::cout << "--- 1. Writing Fields via Type-Safe Enum API ---\n";
    reg.setField(FieldShift::Power,       FieldWidth::Power,       1ULL);
    reg.setField(FieldShift::FanSpeed,    FieldWidth::FanSpeed,    7ULL);
    reg.setField(FieldShift::Temperature, FieldWidth::Temperature, 210ULL);

    std::cout << " Register Binary : " << std::bitset<16>(reg.getRaw()) << "\n\n";

    std::cout << "--- 2. Attempting Overflow Write ---\n";
    reg.setField(FieldShift::FanSpeed, FieldWidth::FanSpeed, 9ULL);
    std::cout << " Register Binary : " << std::bitset<16>(reg.getRaw()) << " (Unchanged!)\n\n";

    std::cout << "--- 3. Reading Fields via Enum API ---\n";
    std::cout << " Power State     : " << reg.getField(FieldShift::Power,       FieldWidth::Power) << "\n";
    std::cout << " Fan Speed       : " << reg.getField(FieldShift::FanSpeed,    FieldWidth::FanSpeed) << " / 7\n";
    std::cout << " Temperature     : " << reg.getField(FieldShift::Temperature, FieldWidth::Temperature) << " deg C\n";

    std::cout << "========================================================\n";
    return 0;
}
