#include <iostream>
#include <string>
using namespace std;

int main()
{
  string userText;
  
  cout << "Type full sentence with spaces: " << endl;
  getline(cin, userText);
  
  cout << "\nOriginal Text: " << userText << endl;
  cout << "Total Length: " << userText.length() << " characters." << endl;
  
  cout << "Transformed Text: ";
  for (int i = 0; i < userText.length(); i++) {
    if (userText[i] == ' ') {
      userText[i] = '-';
    }
    cout << userText[i];
  }
  cout << endl;
  
    return 0;
}
