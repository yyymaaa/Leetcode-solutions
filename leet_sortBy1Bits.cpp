// Input: arr = [0,1,2,3,4,5,6,7,8]
// Output: [0,1,2,4,8,3,5,6,7]
// Explantion: [0] is the only integer with 0 bits.
// [1,2,4,8] all have 1 bit.
// [3,5,6] have 2 bits.
// [7] has 3 bits.
// The sorted array by bits is [0,1,2,4,8,3,5,6,7]

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