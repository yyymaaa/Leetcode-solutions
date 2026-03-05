#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
int findLongestArithmeticProgression(std::vector<int> arr, int k) {
    std::set<int> noDuplicates (std::begin(arr), std::end(arr));
    std::unordered_map<int, int> ourMap;
    int target = 0;
    int maxLength = 0;

    for (int x : noDuplicates) {
        target = x - k;
        int currentLength = 0;
        if (ourMap.find(target) != ourMap.end()) {
            currentLength = ourMap[target] + 1;
        } else {
            currentLength = 1;
        }
        ourMap[x] = currentLength;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main() {
    std::vector<int> arr = {8, 1, -1, 0, 3, 6, 2, 4, 5, 7, 9};
    int k = 2;

    int result = findLongestArithmeticProgression(arr, k);

    std::cout << "Longest sequence length: " << result << std::endl;

    return 0;
}