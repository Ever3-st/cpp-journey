#include <iostream>
#include <string>
using namespace std;

int main()
{
	int age = 17;
	double gpa = 9.8;
	char grade = 'A';
	bool passed = true;
	string name = "Drowsy";

	cout << "Name: " << name <<endl
	     << "Age: " << age <<endl
	     << "GPA: " << gpa <<endl
	     << "Grade: " << grade <<endl
	     << boolalpha << "Passed: " << passed << endl;

	return 0;
}
