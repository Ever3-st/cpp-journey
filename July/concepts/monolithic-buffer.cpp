#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::string filename = "sample-log.txt";
    std::ifstream fileReader(filename);
    
    if (!fileReader.is_open()) {
      std::cout << "[ERROR] Could not open " << filename << "!\n";
      return 1;
    }
    
    std::cout << "[SYSTEM] File gateway oppened. Allocating monolithic buffer...\n";
    
    std::stringstream textStream;
    
    textStream << fileReader.rdbuf();
    
    fileReader.close();
    
    std::string fileContentBuffer = textStream.str();
    
    std::cout << "[SUCCESS] File completely unmounted from storage.\n";
    std::cout << "[MEMORY] Total bytes sucked into monolithic buffer: " << fileContentBuffer.size() << " bytes.\n";
    std::cout << "--------------------------------------------------\n";
    
    std::cout << "[RAW BUFFER CONTENT]:\n" << fileContentBuffer;
    std::cout << "--------------------------------------------------\n";

    return 0;
}
