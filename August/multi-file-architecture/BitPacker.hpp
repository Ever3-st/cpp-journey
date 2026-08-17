#pragma once
#include <cstdint>

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

class BitPacker {
private:
    uint64_t m_register = 0ULL;
    constexpr uint64_t createMask(uint8_t width) const;

public:
    BitPacker() = default;

    bool setField(FieldShift shift, FieldWidth width, uint64_t value);
    uint64_t getField(FieldShift shift, FieldWidth width) const;
    uint64_t getRaw() const;
    void reset();
};
