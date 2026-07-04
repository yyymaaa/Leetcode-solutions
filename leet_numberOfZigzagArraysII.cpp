#include <iostream>
#include <vector>

class Solution {
private:
    long long MOD = 1000000007;

    std::vector<std::vector<long long>> multiply(const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
        int size = A.size();
        std::vector<std::vector<long long>> C(size, std::vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < size; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    std::vector<std::vector<long long>> power(std::vector<std::vector<long long>> base, long long exp) {
        int size = base.size();
        std::vector<std::vector<long long>> res(size, std::vector<long long>(size, 0));
        for (int i = 0; i < size; i++) {
            res[i][i] = 1;
        }
        while (exp > 0) {
            if (exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int total_states = 2 * m;

        std::vector<std::vector<long long>> T(total_states, std::vector<long long>(total_states, 0));


        for (int x = 0; x < m; x++) {
            int downState = x;
            int upState = x + m;

            for (int y = 0; y < x; y++) {
                T[y][upState] = 1;
            }

            for (int y = x + 1; y < m; y++) {
                T[y + m][downState] = 1;
            }
        }

        std::vector<std::vector<long long>> P = power(T, n - 1);

        std::vector<long long> start(total_states, 1);

        long long total_valid_ways = 0;
        for (int i = 0; i < total_states; i++) {
            long long current_ways = 0;
            for (int j = 0; j < total_states; j++) {
                current_ways = (current_ways + P[i][j] * start[j]) % MOD;
            }
            total_valid_ways = (total_valid_ways + current_ways) % MOD;
        }

        return total_valid_ways;
    }
};

int main() {
    Solution sol;
  
    std::cout << "Test 1: " << sol.zigZagArrays(3, 4, 5) << std::endl;

    std::cout << "Test 2: " << sol.zigZagArrays(3, 1, 3) << std::endl;
    
    return 0;
}