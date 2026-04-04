#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


long long countSubarraysWithSumAndMaxAtMost(std::vector<int> nums, long long k, long long M) {
    long long total_count = 0;
    long long current_sum = 0;
    std::unordered_map<long long, long long> counts;
    counts[0] = 1; 

    for (int N : nums) {
        if (N > M) {
            current_sum = 0;
            counts.clear();
            counts[0] = 1; 
        } else {
            current_sum += N;
            if (counts.find(current_sum - k) != counts.end()) {
                total_count += counts[current_sum - k];
            }
            counts[current_sum]++;
        }
    }
    return total_count;
}

int main() {
    std::vector<int> nums = {2, -1, 2, 1, -2, 3};
    long long k = 3;
    long long M = 2;

    long long result = countSubarraysWithSumAndMaxAtMost(nums, k, M);

    std::cout << "Total Valid Subarrays: " << result << std::endl;

    return 0;
}
