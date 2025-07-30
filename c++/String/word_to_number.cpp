#include <iostream>
#include <string>
using namespace std;

// not completed yet -- --

int main() {
    string n;
    cout << "Enter your word: ";
    getline(cin, n);
    
    if (n == "one") 
        cout << "1";
    else if (n == "ten")
        cout << "10";
    else if (n == "hundred")
        cout << "100";
    else if (n == "thousand")
        cout << "1000";
    else if (n == "ten thousand")
        cout << "10000";
    else if (n == "hundred thousand")
        cout << "100000";
    else if (n == "million")
        cout << "1000000";
    else if (n == "billion")
        cout << "1000000000";
    else 
        cout << "Word not recognized!";

    return 0;
}
