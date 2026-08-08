#include <iostream>
#include <cstdint>
#include <bitset>

constexpr uint64_t FLAG_POWER_ON     = 1ULL << 0;

constexpr uint64_t FAN_SHIFT         = 1;
constexpr uint64_t FAN_MASK          = 0x7ULL << FAN_SHIFT;

constexpr uint64_t TEMP_SHIFT        = 4;
constexpr uint64_t TEMP_MASK         = 0xFFULL << TEMP_SHIFT;

int main() {
    std::cout << "========================================================\n";
    std::cout << "        DAY 05: SYNTHESIS & READ-MODIFY-WRITE           \n";
    std::cout << "========================================================\n";

    uint64_t sensorRegister = 0ULL;

    uint64_t initialFanSpeed = 5ULL;
    uint64_t initialTemp     = 72ULL;

    sensorRegister |= FLAG_POWER_ON;
    sensorRegister |= (initialFanSpeed & 0x7ULL) << FAN_SHIFT;
    sensorRegister |= (initialTemp & 0xFFULL) << TEMP_SHIFT;

    std::cout << "[INIT] Initialized Hardware Register:\n";
    std::cout << " Binary View (Bits 0..15): " << std::bitset<16>(sensorRegister) << "\n\n";

    uint64_t newTemp = 105ULL;
    std::cout << "--- 1. Overwriting Temperature to " << newTemp << "°C ---\n";

    sensorRegister = (sensorRegister & ~TEMP_MASK) | ((newTemp & 0xFFULL) << TEMP_SHIFT);

    std::cout << " Binary View (Bits 0..15): " << std::bitset<16>(sensorRegister) << "\n\n";

    std::cout << "--- 2. Toggling Power Switch (XOR) ---\n";
    sensorRegister ^= FLAG_POWER_ON;

    std::cout << " Binary View (Bits 0..15): " << std::bitset<16>(sensorRegister) << "\n\n";

    std::cout << "--- 3. Unpacking Telemetry Data from Register ---\n";

    bool isPowerOn         = (sensorRegister & FLAG_POWER_ON) != 0;
    uint64_t currentFan   = (sensorRegister >> FAN_SHIFT) & 0x7ULL;
    uint64_t currentTemp  = (sensorRegister >> TEMP_SHIFT) & 0xFFULL;

    std::cout << " * Power State : " << (isPowerOn ? "ACTIVE" : "STANDBY") << "\n";
    std::cout << " * Fan Speed   : " << currentFan << " / 7\n";
    std::cout << " * Temperature : " << currentTemp << "°C\n";

    std::cout << "========================================================\n";
    return 0;
}
