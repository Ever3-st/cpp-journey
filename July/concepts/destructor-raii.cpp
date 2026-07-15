#include <iostream>
#include <string>

class SecureBuffer {
private:
	int* m_rawHeapArray;
	size_t m_size;

public:
	SecureBuffer(size_t size) : m_size(size) {
		m_rawHeapArray = new int[size];
		std::cout << "[CONSTRUCTOR] Allocated " << m_size << " integers on the Heap.\n";
	}

	~SecureBuffer() {
		delete[] m_rawHeapArray;
		std::cout << "[DESTRUCTOR] Objects scope ended. Heap memory automatically vaporized!\n";
	}

	void setBit(size_t index, int value) {
		if (index < m_size) {
			m_rawHeapArray[index] = value;
		}
	}
};

int main()
{
	std::cout << "[SYSTEM] Initializing RAII automatic lifecycle tracking...\n";
	std::cout << "--------------------------------------------------\n";

	{
		std::cout << "[SCOPE] Entering local execution block...\n";

		SecureBuffer localBuffer(5000);
		localBuffer.setBit(0,42);

		std::cout << "[SCOPE] Exiting local execution block shortly...\n";
	}

	std::cout << "------------------------------------------------\n";
	std::cout << "[SUCCESS] Main runtime continues. Notice the memory was cleaned up *before* this line!\n";

	return 0;
}
