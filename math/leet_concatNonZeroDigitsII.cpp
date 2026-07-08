#include <iostream>
#include <vector>
#include <string>

std::vector<int> sumAndMultiply(std::string s, std::vector<std::vector<int>>& queries) {
    int m = s.length();
    long long MOD = 1e9 + 7;

    std::vector<long long> power10(m + 1, 1);
    for (int i = 1; i <= m; i++) {
        power10[i] = (power10[i - 1] * 10) % MOD;
    }

    std::vector<long long> pref_x(m + 1, 0);
    std::vector<int> pref_sum(m + 1, 0);
    std::vector<int> pref_count(m + 1, 0); 

    for (int i = 0; i < m; i++) {
        int digit = s[i] - '0';
        
        if (digit != 0) {
            pref_x[i + 1] = (pref_x[i] * 10 + digit) % MOD;
            pref_sum[i + 1] = pref_sum[i] + digit;
            pref_count[i + 1] = pref_count[i] + 1;
        } else {
            pref_x[i + 1] = pref_x[i];
            pref_sum[i + 1] = pref_sum[i];
            pref_count[i + 1] = pref_count[i];
        }
    }

    std::vector<int> answer;
    for (const auto& q : queries) {
        int l = q[0];
        int r = q[1];

        long long current_sum = pref_sum[r + 1] - pref_sum[l];

        int non_zero_count = pref_count[r + 1] - pref_count[l];

        if (non_zero_count == 0) {
            answer.push_back(0);
            continue;
        }

        long long full_x = pref_x[r + 1];
        long long left_part = (pref_x[l] * power10[non_zero_count]) % MOD;

        long long current_x = (full_x - left_part + MOD) % MOD;

        long long query_ans = (current_x * current_sum) % MOD;
        answer.push_back(query_ans);
    }

    return answer;
}

int main() {
    std::string s = "10203004";
    std::vector<std::vector<int>> queries = {{0, 7}, {1, 3}, {4, 6}};
    
    std::vector<int> ans = sumAndMultiply(s, queries);
    
    std::cout << "Output: [";
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << (i == ans.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl; 

    return 0;
}