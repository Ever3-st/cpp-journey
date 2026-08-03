#include <iostream>
#include <cstdint>
#include <bitset>

constexpr uint64_t FLAG_ENGINE_RUNNING = 1ULL << 0;
constexpr uint64_t FLAG_HEADLIGHTS_ON = 1ULL << 1;
constexpr uint64_t FLAG_SECURITY_ARMED = 1ULL << 2;
constexpr uint64_t FLAG_AIRBAG_ACTIVE = 1ULL << 3;

int main()
{
    std::cout << "=========================================================\n";
    std::cout << "        DAY 02: BITWISE OR (|) & BITWISE AND (&)         \n";
    std::cout << "=========================================================\n";
    
    uint64_t vehicleStatus = 0ULL;
    
    std::cout << "[INIT] Vehicle Status Register: "
              << std::bitset<16>(vehicleStatus) << "\n\n";
    
    std::cout << "--- 1. Turning ON Engine & Security System ---\n";
    
    vehicleStatus = vehicleStatus | FLAG_ENGINE_RUNNING | FLAG_SECURITY_ARMED;
    
    std::cout << "Status Register (Binary) : "
              << std::bitset<16>(vehicleStatus) << "\n";
    std::cout << "Status Register (Decimal): " << vehicleStatus << "\n\n";
    
    std::cout << "--- 2. Inspecting Individual Bit States ---\n";
    
    if ((vehicleStatus &FLAG_ENGINE_RUNNING) != 0) {
        std::cout << " [CHECK] Engine status   : ACTIVE (Bit 0 is ON)\n";
    } else {
        std::cout << " [CHECK] Engine status   : OFF\n";
    }
    
    if ((vehicleStatus & FLAG_HEADLIGHTS_ON) != 0) {
        std::cout << " [CHECK] Headlights status: ACTIVE\n";
    } else {
        std::cout << " [CHECK] Headlights status: INACTIVE (Bit 1 is OFF)\n";
    }
    
    if ((vehicleStatus & FLAG_SECURITY_ARMED) != 0) {
        std::cout << " [CHECK] Security status : ARMED (Bit 2 is ON\n";
    }
     std::cout << "========================================================\n";
     return 0;
}
