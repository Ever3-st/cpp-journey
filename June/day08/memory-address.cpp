#include <iostream>
using namespace std;

int main()
{
    int organicApple = 45;
    double gasPrice = 80.45;
    
    cout << "Value of apple: " << organicApple << endl;
    cout << "RAM Address of apple: " << &organicApple << endl;
    
    cout << "Value of apple: " << gasPrice << endl;
    cout << "RAM Address of gas: " << &gasPrice << endl;

    return 0;
}
