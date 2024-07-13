#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool containsOnlyAlphabetic(const string& str) {
    for (char c : str) {
        if (! isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    bool result = containsOnlyAlphabetic(input);
    if (result) {
        cout << "The string contains only alphabetic characters." <<endl;
    } else {
        cout << "The string does not contain only alphabetic characters." <<endl;
    }

    return 0;
}