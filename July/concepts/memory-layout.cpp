#include <iostream>
#include <string>

struct TelemetryData {
    int nodeID;
    double voltage;
};

int main()
{
    std::cout << "[SYSTEM] Exploring physical hardware memory layers...\n";
    std::cout << "--------------------------------------------------\n";
    
    TelemetryData stackObject;
    stackObject.nodeID = 101;
    stackObject.voltage = 3.3;
    
    TelemetryData* heapObject = new TelemetryData();
    heapObject->nodeID = 202;
    heapObject->voltage = 5.0;
    
    std::cout << "[STACK] Object Address: " << &stackObject << " (High Memory Space)\n";
    std::cout << "[HEAP]  Pointer Address: " << heapObject << " (Low Reservoir Space)\n";
    std::cout << "------------------------------------------------\n";
    
    delete heapObject;
    std::cout << "[CLEANUP] HEAP memory released back to the OS gateway.\n";

    return 0;
}
