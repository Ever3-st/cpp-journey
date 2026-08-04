#include <iostream>
#include <cstdint>
#include <bitset>

constexpr uint64_t FLAG_ENGINE_RUNNING = 1ULL << 0;
constexpr uint64_t FLAG_HEADLIGHTS_ON = 1ULL << 1;
constexpr uint64_t FLAG_SECURITY_ARMED = 1ULL << 2;

int main () {
    std::cout << "========================================================\n";
    std::cout << "     DAY 03: BITWISE XOR (^)' NOT (~), AND CLEARING     \n";
    std::cout << "========================================================\n";
    
    uint64_t vehicleStatus = FLAG_ENGINE_RUNNING | FLAG_SECURITY_ARMED;
    
    std::cout << "Initial Status          : "
              << std::bitset<16>(vehicleStatus) << " (Decimal: " << vehicleStatus << ")\n\n";
              
    std::cout << "--- 1. Disarming Security System (Clearing Bit 2) ---\n";
    
    vehicleStatus = vehicleStatus & (~FLAG_SECURITY_ARMED);
    
    std::cout << "After Disarming        : "
              << std::bitset<16>(vehicleStatus) << " (Bit 2 is now 0)\n\n";
              
    std::cout << "--- 2. Toggling Headlights Switch ---\n";
    
    vehicleStatus = vehicleStatus ^ FLAG_HEADLIGHTS_ON;
    std::cout << "Toggle #1 (Turn ON)    : "
              << std::bitset<16>(vehicleStatus) << " (Bit 1 is ON)\n";
              
    vehicleStatus = vehicleStatus ^ FLAG_HEADLIGHTS_ON;
    std::cout << "Toggle #2 (Turn OFF)   : "
              <<std::bitset<16>(vehicleStatus) << " (Bit 1 is OFF again)\n";
    
    std::cout << "========================================================\n";
    return 0;
}
