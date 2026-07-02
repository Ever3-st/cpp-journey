#include <iostream>
using namespace std;

int main()
{
    int score = 100;
    int* ptr = &score;
    
    cout << "Value of score: " << score << endl;
    cout << "Address stored in ptr: " << ptr << endl;
    
    *ptr = 150;
    
    cout << "New value of score: " << score << endl;

    return 0;
}
