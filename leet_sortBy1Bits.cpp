#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <climits>
#include <algorithm>

std::vector<int> sortByBits(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = std::bitset<32>(a).count();
            int countB = std::bitset<32>(b).count();
            if (countA == countB)
                return a < b;
            return countA < countB;
        });
        return arr;
    }

int main() {
    std::vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    std::vector<int> result = sortByBits(arr);

    std::cout << "Sorted by bits: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}