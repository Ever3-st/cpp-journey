#include <iostream>
#include <string>
#include <string_view>

int main() {
    
    std::string rawLogBuffer = "[INFO] Booting system.\n[WARN] Power fluctuation detected here!\n[ERROR] Critical shut down.";

    std::cout << "[SYSTEM] Initializing dynamic zero-copy stream slicing...\n";
    std::cout << "--------------------------------------------------\n";

    std::string_view bufferWindow = rawLogBuffer;
    int lineCounter = 1;
  
    while (!bufferWindow.empty()) {
        
        size_t newlinePos = bufferWindow.find('\n');

        if (newlinePos == std::string_view::npos) {
            std::string_view finalLine = bufferWindow;
            
            std::cout << "Line " << lineCounter << " (Remnant) -> " << finalLine 
                      << " [Bytes: " << finalLine.size() << "]\n";
            
            break;
        }
      
        std::string_view currentLine = bufferWindow.substr(0, newlinePos);
        
        std::cout << "Line " << lineCounter << "           -> " << currentLine 
                  << " [Bytes: " << currentLine.size() << "]\n";
      
        bufferWindow.remove_prefix(newlinePos + 1);

        lineCounter++;
    }

    std::cout << "--------------------------------------------------\n";
    std::cout << "[SUCCESS] Entire buffer sliced dynamically with zero heap allocations.\n";

    return 0;
}
