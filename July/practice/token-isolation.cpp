#include <iostream>
#include <string>
#include <string_view>

int main() {
  
    std::string textData = "C++ high-performance zero-copy string parsing";

    std::cout << "[TOKENIZER] Starting zero-copy lexical analysis...\n";
    std::cout << "--------------------------------------------------\n";

    std::string_view window = textData;
    int tokenCount = 1;

    while (!window.empty()) {
      
        size_t spacePos = window.find(' ');

        if (spacePos == std::string_view::npos) {
            std::string_view finalToken = window;
            std::cout << "Token #" << tokenCount << ": [" << finalToken << "]\n";
            break; 
        }

        std::string_view currentToken = window.substr(0, spacePos);
        std::cout << "Token #" << tokenCount << ": [" << currentToken << "]\n";
      
        window.remove_prefix(spacePos + 1);

        tokenCount++;
    }

    std::cout << "--------------------------------------------------\n";
    std::cout << "[SUCCESS] Lexical parsing completed successfully.\n";
    
    return 0;
}
