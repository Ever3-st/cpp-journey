#include <iostream>
using namespace std;

int main()
{
    int items[7] = {21, 34, 48, 60, 73,88, 97};
    
    for (int i = 0; i < 7; i++) {
        cout << "Slot " << i << " holds: " << items[i] << endl;
    }
    
    return 0;
}
