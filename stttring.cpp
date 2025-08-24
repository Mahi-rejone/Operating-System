#include <iostream> 
#include <string> 
using namespace std; 
 
int main() { 
    string str; 
    cout << "Enter a string: "; 
    cin >> str;

    if (str.find("add") != string::npos) { 
        cout << "The string contains 'add': Yes" << endl; 
    } else { 
        cout << "The string contains 'add': No" << endl; 
    } 

    if (str.length() % 2 == 0) { 
        cout << "Length: Even" << endl; 
    } else { 
        cout << "Length: Odd" << endl; 
    } 
    if (!str.empty() && str.back() == 'e') { 
        cout << "Ends with 'e': Yes" << endl; 
    } else { 
        cout << "Ends with 'e': No" << endl; 
    } 
 
    return 0; 
}