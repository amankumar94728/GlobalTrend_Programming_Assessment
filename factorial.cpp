#include <iostream>
using namespace std;
unsigned long long factorial(int n) {
    if (n < 0) {
        cerr << "Factorial is not defined for negative numbers." << endl;
        return 0;
    }

    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    unsigned long long result = factorial(num);
    cout << "Factorial of " << num << " is " << result <<endl;

    return 0;
}