#include <iostream>
#include <vector>
 // a binary array is stable if:
 //The number of occurences of 0 in arr is exactly zero
 //The number of occurences of 1 in arr is exactly one
 //Each subarray or arr with size greater than limit must contain both 0 and 1

int numberOfStableArrays(int zero, int one, int limit) {
        int MOD = 1e9 + 7;
        std::vector<std::vector<std::vector<long long>>> dp(zero + 1, std::vector<std::vector<long long>>(one + 1, std::vector<long long>(2, 0)));
    
        for (int i = 1; i <= std::min(zero, limit); ++i) {
            dp[i][0][0] = 1;
        }

        for (int j = 1; j <= std::min(one, limit); ++j) {
            dp[0][j][1] = 1;
        }

    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) {
            if (i > 0) {
                if (j == 0) {
                    if (i <= limit) dp[i][j][0] = 1;
                } else {
                    dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                    if (i > limit) {
                    dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + MOD) % MOD;
                }
            }
        }

        if (j > 0) {
            if (i == 0) {
                if (j <= limit) dp[i][j][1] = 1;
            } else {
                dp[i][j][1] = (dp[i][j - 1][1] + dp[i][j - 1][0]) % MOD;
                if (j > limit) {
                    dp[i][j][1] = (dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0] + MOD) % MOD;
                }
            }
        }
    }
}
    return (dp[zero][one][0] + dp[zero][one][1]) % MOD; 
    }


int main() {
    // Example 1: Expected 2
    std::cout << "Example 1 (1, 1, 2): " << numberOfStableArrays(1, 1, 2) << std::endl;

    // Example 2: Expected 1
    std::cout << "Example 2 (1, 2, 1): " << numberOfStableArrays(1, 2, 1) << std::endl;

    // Example 3: Expected 14
    std::cout << "Example 3 (3, 3, 2): " << numberOfStableArrays(3, 3, 2) << std::endl;

    // Hard Test: Expected 733857642
    // Yesterday's code would take a long time; this finishes instantly.
    std::cout << "Hard Test (500, 500, 10): " << numberOfStableArrays(500, 500, 10) << std::endl;

    return 0;
}