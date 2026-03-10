#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int maxDistincSubstringLenghtInSessions(std::string sessionString) {
    int globalMax = 0;
    int n = sessionString.length();
    int i = 0;

    while (i < n) {
        if (sessionString[i] == '*') {
            i++;
            continue;
        }

        int left = i;
        std::vector<int> count(26, 0);
        int sessionLocalMax = 0;

        for (int right = i; right < n && sessionString[right] != '*'; ++right) {
            int charIdx = sessionString[right] - 'a';

            while (count[charIdx] > 0) {
                count[sessionString[left] - 'a']--;
                left++;
            }

            count[charIdx]++;

            sessionLocalMax = std::max(sessionLocalMax, right - left + 1);

            i = right;
        }
        globalMax = std::max(globalMax, sessionLocalMax);
        i++;
    }
    return globalMax;
}

int main() {
    // Test Case: Two sessions "abcabcbb" and "pwwkew"
    std::string input = "abcabcbb*pwwkew"; 
    std::cout << "Max unique substring length: " << maxDistincSubstringLenghtInSessions(input) << std::endl;
    return 0;
}