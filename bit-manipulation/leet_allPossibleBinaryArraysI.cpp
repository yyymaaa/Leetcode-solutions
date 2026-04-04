#include <iostream>
#include <vector>
//a binary array is stable if the number of ocurrences of 0 is exactly zero,
//if the number of occurrences of 1 is exactly one,
//each subarray of arr with a size greater than limit must contain both 0 and 1. 

int numberOfStableArrays(int one, int zero, int limit) {
    int MOD = 1e9 + 7;
    std::vector<std::vector<std::vector<long long>>> dp(zero + 1, std::vector<std::vector<long long>>(one + 1, std::vector<long long>(2, 0)));

    for (int i = 1; i <= std::min(zero, limit); ++i) {
        dp[i][0][0] = 1;
    }

    for (int j = 1; j <= std::min(one, limit); ++j) {
        dp[0][j][1] = 1;
    }

    for (int i = 1; i <= zero; ++i) {
        for (int j = 1; j <= one; ++j) {
            for (int len = 1; len <= limit && i - len >= 0; ++len) {
                dp[i][j][0] = (dp[i][j][0] + dp[i - len][j][1]) % MOD; 
            }

            for (int len = 1; len <= limit && j - len >= 0; ++len) {
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - len][0]) % MOD;
            }
        }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}

int main() {
    std::cout <<"Result: " << numberOfStableArrays(1, 1, 2) << std::endl;
    return 0;
}