#include <iostream>
#include <cstdint>
#include <bitset>

class BitRegister {
private:
    uint64_t m_register = 0ULL;

    constexpr uint64_t createMask(uint8_t width) const {
        return (width >= 64) ? ~0ULL : ((1ULL << width) - 1ULL);
    }

public:
    BitRegister() = default;

    bool setField(uint8_t width, uint8_t shift, uint64_t value) {
        if (shift >= 64 || width == 0) return false;
        
        uint64_t maxVal = createMask(width);
        if (value > maxVal) {
            std::cout << " [REJECTED] Value " << value << " exceeds " 
                      << maxVal << " (" << (int)width << " bits)\n";
            return false;
        }

        uint64_t fieldMask = maxVal << shift;
        m_register = (m_register & ~fieldMask) | ((value & maxVal) << shift);
        return true;
    }

    uint64_t getField(uint8_t width, uint8_t shift) const {
        if (shift >= 64 || width == 0) return 0ULL;
        return (m_register >> shift) & createMask(width);
    }

    uint64_t getRaw() const {
        return m_register;
    }

    void reset() {
        m_register = 0ULL;
    }
};

int main() {
    std::cout << "========================================================\n";
    std::cout << "     DAY 10: CLASS ENCAPSULATION FOR BIT REGISTERS      \n";
    std::cout << "========================================================\n";

    BitRegister reg;

    std::cout << "--- 1. Writing Fields via Public API ---\n";
    reg.setField(1, 0, 1ULL);
    reg.setField(3, 1, 5ULL);
    reg.setField(8, 4, 95ULL);

    std::cout << " Register Binary : " << std::bitset<16>(reg.getRaw()) << "\n\n";

    std::cout << "--- 2. Attempting Invalid Write ---\n";
    reg.setField(3, 1, 12ULL);
    std::cout << " Register Binary : " << std::bitset<16>(reg.getRaw()) << " (Unchanged!)\n\n";

    std::cout << "--- 3. Reading Fields via Public API ---\n";
    std::cout << " Power State     : " << reg.getField(1, 0) << "\n";
    std::cout << " Fan Speed       : " << reg.getField(3, 1) << " / 7\n";
    std::cout << " Temperature     : " << reg.getField(8, 4) << " deg C\n";

    std::cout << "========================================================\n";
    return 0;
}
