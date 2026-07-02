#include <iostream>
using namespace std;

int main ()
{
    int maxNumber;
    int totalSum = 0;
    
    cout << "Enter a number to sum up to: ";
    cin >> maxNumber;
    
    for (int i=1; i <= maxNumber; i++) {
        
        totalSum = totalSum + i;
    }
    
    cout << "The grand total is: " << totalSum << endl;
    
    return 0;
}
