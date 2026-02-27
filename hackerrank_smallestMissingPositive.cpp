#include <iostream>
#include <vector>
#include <algorithm>

int findSmallestMissingPositive(std::vector<int> orderNumbers) {
    int length = orderNumbers.size();
    int temp = 0;
    int i = 0;
    while (i < length) {
        int target_index = orderNumbers[i] - 1;
        if (orderNumbers[i] > 0 && orderNumbers[i] <= length && orderNumbers[i] != length) {
            std::swap(orderNumbers[i], orderNumbers[orderNumbers[i] - 1]);
        } else {
            i++;
        }
    }
    for (int j = 0; j < length; j++) {
        if (orderNumbers[j] != j + 1) {
            return j + 1;
        }
    }
    return length + 1;
}

int main() {
    std::vector<int> test1 = {3, 4, -1, 1}; 
    std::cout << "Test 1 [3, 4, -1, 1]: " << findSmallestMissingPositive(test1) << std::endl;

    std::vector<int> test2 = {1, 2, 3}; 
    std::cout << "Test 2 [1, 2, 3]: " << findSmallestMissingPositive(test2) << std::endl;

    std::vector<int> test3 = {}; 
    std::cout << "Test 3 []: " << findSmallestMissingPositive(test3) << std::endl;

    std::vector<int> test4 = {1, 1, 10, 2}; 
    std::cout << "Test 4 [1, 1, 10, 2]: " << findSmallestMissingPositive(test4) << std::endl;

    return 0;
}