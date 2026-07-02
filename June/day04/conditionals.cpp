#include <iostream>
using namespace std;

int main()
{
    int guess;
    
    cout << "Enter your guess (1-10: ";
    cin >> guess;
    
    if (guess == 7) {
        cout << "Pefect! You Win!" << endl;
    }
    else if (guess == 6 || guess== 8) {
        cout << "So close! Just one number off" << endl;
    }
    else {
        cout << "Not even close! you loss" << endl;
    }
    
    return 0;
}
