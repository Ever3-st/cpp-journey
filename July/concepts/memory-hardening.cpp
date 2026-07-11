#include <iostream>
#include <string>
#include <string_view>
#include <stdexcept>

int main() {
    std::string secureBuffer = "SECURE_DATA_PACKET";
    std::string_view window = secureBuffer;

    std::cout << "[SYSTEM] Activating defensive memory boundaries...\n";
    std::cout << "--------------------------------------------------\n";

    size_t unsafeIndex = 50;

    std::cout << "[GUARD 1] Attempting to read index " << unsafeIndex << "...\n";
    
    try {
        
        char dataBit = window.at(unsafeIndex); 
        std::cout << "Data: " << dataBit << "\n";
    } 
    catch (const std::out_of_range& error) {
        std::cout << "   [BLOCKED] Memory overrun prevented successfully!\n";
        std::cout << "   Diagnostic message: " << error.what() << "\n";
    }

    std::cout << "--------------------------------------------------\n";

    size_t targetOffset = 5;
    size_t requestedLength = 30;
    std::cout << "[GUARD 2] Validating slice footprint: Offset " << targetOffset 
              << ", Length " << requestedLength << "\n";

    if (targetOffset + requestedLength > window.size()) {
        std::cout << "   [BLOCKED] Dynamic slice aborted! Request exceeds memory window.\n";
        std::cout << "   [FALLBACK] Clamping view to maximum safe remaining size instead.\n";
        
        std::string_view safeSlice = window.substr(targetOffset, window.size() - targetOffset);
        std::cout << "   Safe Extracted Token: [" << safeSlice << "]\n";
    } else {
        std::string_view normalSlice = window.substr(targetOffset, requestedLength);
        std::cout << "   Extracted Token: [" << normalSlice << "]\n";
    }

    std::cout << "--------------------------------------------------\n";
    std::cout << "[SUCCESS] Core memory architecture hardened against execution faults.\n";

    return 0;
}
