#include <iostream>

int sumOfDigits(int num) {
    num = abs(num);
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    int result = sumOfDigits(num);
    std::cout << "Sum of the digits of " << num << " is " << result << std::endl;

    return 0;
}