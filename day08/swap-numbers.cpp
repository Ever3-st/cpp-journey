#include <iostream>
using namespace std;

void RealSwap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    
    RealSwap(a, b);
    
    cout << "After RealSwap -> a: " << a << " | b: " << b << endl;

    return 0;
}
