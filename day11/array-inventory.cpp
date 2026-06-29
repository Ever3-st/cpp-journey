#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fruits[4] = {"apples", "mango", "oranges", "kiwi"};
    int counts[4] = {15,11,7,3};
    
    for (int i = 0; i < 4; i++) {
        cout << fruits[i] << " = " << counts[i] << endl;
    }
    
    return 0;
}
