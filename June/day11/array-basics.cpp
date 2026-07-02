#include <iostream>
using namespace std;

int main()
{
    int scores[3] = {85, 92, 78};
    
    cout << "First score (Slot 0): " << scores[0] << endl;
    cout << "Second score (Slot 1): " << scores[1] << endl;
    
    scores[2] = 95;
    cout << "Updated Third score (Slot 2): " << scores[2] << endl;

    return 0;
}
