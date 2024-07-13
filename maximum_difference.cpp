#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
int findMaxDifference(const vector<int>& nums) {
    if (nums.empty()) {
        cerr << "The array is empty." << endl;
        return 0;
    }

    int minElement = numeric_limits<int>::max();
    int maxElement = numeric_limits<int>::min();

    for (int num : nums) {
        if (num < minElement) {
            minElement = num;
        }
        if (num > maxElement) {
            maxElement = num;
        }
    }

    return maxElement - minElement;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = findMaxDifference(nums);
    cout << "The maximum difference between any two elements in the array is: " << result <<endl;

    return 0;
}
