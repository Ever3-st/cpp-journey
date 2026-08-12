#include <iostream>
#include <cstdint>
#include <bitset>

struct TelemetryData {
    bool     powerOn;
    uint8_t  fanSpeed;
    uint16_t temperature;
};

constexpr uint64_t POWER_SHIFT = 0;
constexpr uint64_t POWER_MASK  = 1ULL << POWER_SHIFT;

constexpr uint64_t FAN_SHIFT   = 1;
constexpr uint64_t FAN_MASK    = 0x7ULL << FAN_SHIFT;

constexpr uint64_t TEMP_SHIFT  = 4;
constexpr uint64_t TEMP_MASK   = 0xFFULL << TEMP_SHIFT;

constexpr uint64_t createMask(uint8_t width) {
    return (width >= 64) ? ~0ULL : ((1ULL << width) - 1ULL);
}

uint64_t encodeTelemetry(const TelemetryData& data) {
    uint64_t rawRegister = 0ULL;
    if (data.powerOn) {
        rawRegister |= POWER_MASK;
    }

    rawRegister |= ((static_cast<uint64_t>(data.fanSpeed) & createMask(3)) << FAN_SHIFT);
    rawRegister |= ((static_cast<uint64_t>(data.temperature) & createMask(8)) << TEMP_SHIFT);

    return rawRegister;
}

TelemetryData decodeTelemetry(uint64_t rawRegister) {
    TelemetryData data;

    data.powerOn = (rawRegister & POWER_MASK) != 0;
    data.fanSpeed = static_cast<uint8_t>((rawRegister >> FAN_SHIFT) & createMask(3));
    data.temperature = static_cast<uint16_t>((rawRegister >> TEMP_SHIFT) & createMask(8));

    return data;
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "     DAY 09: STRUCT-TO-REGISTER ENCODING & DECODING    \n";
    std::cout << "========================================================\n";

    TelemetryData originalData;
    originalData.powerOn     = true;
    originalData.fanSpeed    = 6;
    originalData.temperature = 185;

    std::cout << "--- 1. Original C++ Struct Values ---\n";
    std::cout << " Power On    : " << (originalData.powerOn ? "true" : "false") << "\n";
    std::cout << " Fan Speed   : " << (int)originalData.fanSpeed << " / 7\n";
    std::cout << " Temperature : " << originalData.temperature << " deg C\n\n";

    uint64_t packedRegister = encodeTelemetry(originalData);

    std::cout << "--- 2. Encoded Raw 64-Bit Register ---\n";
    std::cout << " Raw Binary  : " << std::bitset<16>(packedRegister) << "\n";
    std::cout << " Hex Output  : 0x" << std::hex << packedRegister << std::dec << "\n\n";

    TelemetryData restoredData = decodeTelemetry(packedRegister);

    std::cout << "--- 3. Decoded Restored Struct Values ---\n";
    std::cout << " Power On    : " << (restoredData.powerOn ? "true" : "false") << "\n";
    std::cout << " Fan Speed   : " << (int)restoredData.fanSpeed << " / 7\n";
    std::cout << " Temperature : " << restoredData.temperature << " deg C\n";

    std::cout << "========================================================\n";
    return 0;
}
