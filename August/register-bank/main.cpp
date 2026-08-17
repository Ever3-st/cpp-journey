#include <iostream>
#include <cstdint>
#include <array>
#include <bitset>

enum class RegisterID : uint8_t {
    Control   = 0,
    Telemetry = 1,
    COUNT     = 2
};

enum class FieldShift : uint8_t {
    
    PowerState  = 0,
    SafetyLock  = 1,
    FanSpeed    = 0,
    Temperature = 3
};

enum class FieldWidth : uint8_t {
    PowerState  = 1,
    SafetyLock  = 1,
    FanSpeed    = 3,
    Temperature = 8
};

class SystemRegistry {
private:
    std::array<uint64_t, static_cast<size_t>(RegisterID::COUNT)> m_bank{};

    constexpr uint64_t createMask(uint8_t width) const {
        return (width >= 64) ? ~0ULL : ((1ULL << width) - 1ULL);
    }

public:
    SystemRegistry() = default;

    bool writeField(RegisterID reg, FieldShift fieldShift, FieldWidth fieldWidth, uint64_t value) {
        size_t regIdx = static_cast<size_t>(reg);
        if (regIdx >= m_bank.size()) return false;

        uint8_t shift = static_cast<uint8_t>(fieldShift);
        uint8_t width = static_cast<uint8_t>(fieldWidth);
        if (shift >= 64 || width == 0) return false;

        uint64_t maxVal = createMask(width);
        if (value > maxVal) return false;

        uint64_t fieldMask = maxVal << shift;
        m_bank[regIdx] = (m_bank[regIdx] & ~fieldMask) | ((value & maxVal) << shift);
        return true;
    }

    uint64_t readField(RegisterID reg, FieldShift fieldShift, FieldWidth fieldWidth) const {
        size_t regIdx = static_cast<size_t>(reg);
        if (regIdx >= m_bank.size()) return 0ULL;

        uint8_t shift = static_cast<uint8_t>(fieldShift);
        uint8_t width = static_cast<uint8_t>(fieldWidth);
        if (shift >= 64 || width == 0) return 0ULL;

        return (m_bank[regIdx] >> shift) & createMask(width);
    }

    uint64_t getRawRegister(RegisterID reg) const {
        size_t regIdx = static_cast<size_t>(reg);
        return (regIdx < m_bank.size()) ? m_bank[regIdx] : 0ULL;
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << "     DAY 13: MULTI-REGISTER BANK ARCHITECTURE           \n";
    std::cout << "========================================================\n";

    SystemRegistry registry;

    registry.writeField(RegisterID::Control, FieldShift::PowerState, FieldWidth::PowerState, 1ULL);
    registry.writeField(RegisterID::Control, FieldShift::SafetyLock, FieldWidth::SafetyLock, 1ULL);

    registry.writeField(RegisterID::Telemetry, FieldShift::FanSpeed, FieldWidth::FanSpeed, 5ULL);
    registry.writeField(RegisterID::Telemetry, FieldShift::Temperature, FieldWidth::Temperature, 88ULL);

    std::cout << "--- 1. Raw Register Bank Inspection ---\n";
    std::cout << " Control Reg [0]   Binary : " << std::bitset<16>(registry.getRawRegister(RegisterID::Control)) << "\n";
    std::cout << " Telemetry Reg [1] Binary : " << std::bitset<16>(registry.getRawRegister(RegisterID::Telemetry)) << "\n\n";

    std::cout << "--- 2. Unpacking Targeted Bank Fields ---\n";
    std::cout << " Control -> Power Active : " << registry.readField(RegisterID::Control, FieldShift::PowerState, FieldWidth::PowerState) << "\n";
    std::cout << " Control -> Safety Lock  : " << registry.readField(RegisterID::Control, FieldShift::SafetyLock, FieldWidth::SafetyLock) << "\n";
    std::cout << " Telemetry -> Fan Speed  : " << registry.readField(RegisterID::Telemetry, FieldShift::FanSpeed, FieldWidth::FanSpeed) << " / 7\n";
    std::cout << " Telemetry -> Temp Deg C : " << registry.readField(RegisterID::Telemetry, FieldShift::Temperature, FieldWidth::Temperature) << " C\n";

    std::cout << "========================================================\n";
    return 0;
}
