#include <iostream>
#include <string>
#include <algorithm>

int maxNumberOfBalloons(std::string text) {
        int counts[26] = {0};

        for (char c : text) {
            counts[c - 'a']++;
        }

        int b = counts['b' - 'a'];
        int a = counts['a' - 'a'];
        int l = counts['l' - 'a'] / 2;
        int o = counts['o' - 'a'] / 2;
        int n = counts['n' - 'a'];

        return std::min({b, a, l, o, n});
    }

int main() {
    std::string text1 = "nlaebolko";
    std::cout << "Test 1: " << maxNumberOfBalloons(text1) << std::endl;

    std::string text2 = "loonbalxballpoon";
    std::cout << "Test 2: " << maxNumberOfBalloons(text2) << std::endl;

    std::string text3 = "leetcode";
    std::cout << "Test 3: " << maxNumberOfBalloons(text3) << std::endl;

    return 0;
}