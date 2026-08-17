#include "BitPacker.hpp"
#include <iostream>

constexpr uint64_t BitPacker::createMask(uint8_t width) const {
    return (width >= 64) ? ~0ULL : ((1ULL << width) - 1ULL);
}

bool BitPacker::setField(FieldShift fieldShift, FieldWidth fieldWidth, uint64_t value) {
    uint8_t shift = static_cast<uint8_t>(fieldShift);
    uint8_t width = static_cast<uint8_t>(fieldWidth);

    if (shift >= 64 || width == 0) return false;

    uint64_t maxVal = createMask(width);
    if (value > maxVal) {
        std::cout << " [REJECTED] Value " << value << " exceeds limit " << maxVal << "\n";
        return false;
    }

    uint64_t fieldMask = maxVal << shift;
    m_register = (m_register & ~fieldMask) | ((value & maxVal) << shift);
    return true;
}

uint64_t BitPacker::getField(FieldShift fieldShift, FieldWidth fieldWidth) const {
    uint8_t shift = static_cast<uint8_t>(fieldShift);
    uint8_t width = static_cast<uint8_t>(fieldWidth);

    if (shift >= 64 || width == 0) return 0ULL;
    return (m_register >> shift) & createMask(width);
}

uint64_t BitPacker::getRaw() const {
    return m_register;
}

void BitPacker::reset() {
    m_register = 0ULL;
}
