#include <iostream>
using namespace std;

int main()
{
	int a = 10, b = 3;

	// Comparison operators
	cout << boolalpha;
	cout << "\n-- Comparison --" << endl
	     << "a == b: " << (a == b) << endl
	     << "a != b: " << (a != b) << endl
	     << "a > b: " << (a > b) << endl
	     << "a < b: " << (a < b) << endl
	     << "a >= b: " << (a >= b) <<endl
	     << "a <= b: " << (a <= b) <<endl;

	// Logical operators
	bool x = true, y = false;
	cout << "\n-- Logical --" << endl
	     << "x && y: " << (x && y) << endl
	     << "x || y: " << (x || y) << endl
	     << "!x;     " << (!x)     << endl;

	return 0;
}
