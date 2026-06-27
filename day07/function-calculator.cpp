#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

int main()
{
    double num1, num2;
    char op;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter an operator ( +, -, *, /): ";
    cin >> op;
    
    cout << "Result: ";
    if (op == '+') {
        cout << add(num1, num2) << endl;
    }
    else if (op == '-') {
        cout << subtract(num1, num2) << endl;
    }
    else if (op == '*') {
        cout << multiply(num1, num2) << endl;
    }
    else if (op == '/') {
        cout << divide(num1, num2) << endl;
    }
    else {
        cout << "Invalid Operator!" << endl;
    }
    
    return 0;
}
