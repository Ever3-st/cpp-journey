#include <iostream>
#include <string>
using namespace std;

int main()
{
	int age;
	string name;
	double gpa;
	string grade;
	int marks;

	cout << "Enter your name: ";
	cin >> name;

	cout << "Enter your age: ";
	cin >> age;

	cout << "Enter your gpa: ";
	cin >> gpa;

	cout << "Enter your grade: ";
	cin >> grade;

	cout << "Enter your marks: ";
	cin >> marks;


	cout << "\n--- Your Profile ---" << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "GPA: " << gpa << endl;
	cout << "Grade: " << grade << endl;
	cout << "Marks: " << marks << endl;

	return 0;
}
