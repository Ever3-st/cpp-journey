#include <iostream>
#include <string>

class TelemetryNode {
private:
	std::string m_nodeName;
	double m_signalStrength;

public:
	TelemetryNode(std::string name, double signal)
		: m_nodeName(name), m_signalStrength(signal) {}

	void displayMetrics() const {
		std::cout << "  Node: " << m_nodeName << " | Signal: " << m_signalStrength << " dBm\n";
	}

	void adjustSignal(double offset) {
		m_signalStrength += offset;

	}
};

void processNodeSecurely(const TelemetryNode& node) {
	std::cout << "[GATEWAY] Analyzing node memory footprint (0 Copy)...\n";

	node.displayMetrics();

}

int main()
{
	std::cout << "[SYSTEM] Initializing Const-Correct architecture...\n";
	std::cout << "--------------------------------------------------\n";

	TelemetryNode masterNode("Alpha-Station", -72.4);

	processNodeSecurely(masterNode);

	std::cout << "--------------------------------------------------\n";
	std::cout << "[SUCCESS] Object state safely verified with zero memory allocations.\n";

	return 0;
}
