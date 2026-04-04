#include <bitset>
#include <string>
#include <iostream>
#include <vector>

int solution(int N) {
    std::string binary = std::bitset<32>(N).to_string();
    
    // It is very important to initialize to 0, learnt that from an error
    bool started = false;
    int currentGap = 0;
    int maxGap = 0; 

    for (int i = 0; i < (int)binary.length(); i++) {
        char c = binary[i];

        if (c == '1') {
            if (started) {
                if (currentGap > maxGap) {
                    maxGap = currentGap;
                }
            }
            started = true;
            currentGap = 0;
        } 
        else if (started) {
            currentGap++;
        }
    }

    return maxGap;
}

int main() {
    // for the test cases, let's use a list
    std::vector<int> testCases = {9, 529, 20, 1041, 32};
    
    for (int n : testCases) {
        std::cout << "Input: " << n 
                  << " (Binary: " << std::bitset<12>(n) << ")" // i want to just 12 bits for clarity
                  << " -> Max Gap: " << solution(n) << std::endl;
    }

    return 0;
}