#include <iostream>
using namespace std;

void doubleValue(int* p) {
    *p = *p * 2;
}

int main()
{
    int gold = 50;
    
    doubleValue(&gold);
    
    cout << "Current gold: " << gold << endl;
    
    return 0;
}
