#include <iostream>
using namespace std;

int main()
{
    cout << "Starting the search..." << endl;
    
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;
        }
        
        if (i == 8) {
            cout << "Found 8! Breaking out of the loop completely." << endl;
            break;
        }
        
        cout <<"Checking number: " << i << endl;
    }
    
    cout << "Loop finished." << endl;
    return 0;
}
