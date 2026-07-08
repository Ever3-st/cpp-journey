#include <iostream>
#include <string>
#include <string_view>

int main() 
{
    
    std::string rawLogBuffer = "[INFO] 10:00:02 Boot\n[WARN] 10:00:12 Voltage Spike";

    std::cout << "[SYSTEM] Initializing memory-efficient log parsing...\n";
    std::cout << "--------------------------------------------------\n";

    std::string_view bufferWindow = rawLogBuffer;

    std::string_view firstLog  = bufferWindow.substr(0, 20);
    std::string_view secondLog = bufferWindow.substr(21, 29);

    std::cout << "[WINDOW 1] " << firstLog << "\n";
    std::cout << "[WINDOW 2] " << secondLog << "\n";
    std::cout << "--------------------------------------------------\n";

    std::cout << "[RAM] Raw Buffer Base Address: " << (void*)rawLogBuffer.data() << "\n";
    std::cout << "[RAM] First Window Address:    " << (void*)firstLog.data() << "\n";
    std::cout << "[RAM] Second Window Address:   " << (void*)secondLog.data() << "\n";
    
    std::cout << "--------------------------------------------------\n";
    std::cout << "[DIAGNOSTIC] Notice that Window 2 starts exactly 21 bytes after the Base Address.\n";
    std::cout << "             No copies were made. They are looking at the exact same memory allocation!\n";

    return 0;
}
