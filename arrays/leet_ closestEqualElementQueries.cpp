#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

std::vector<int> solveQueries(std::vector<int>& nums, std::vector<int>& queries) {
        std::unordered_map<int, std::vector<int>> ourMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ourMap[nums[i]].push_back(i);
        }

        std::vector<int> results;

        for (int i = 0; i < queries.size(); i++) {
            int queryIdx = queries[i];
            int targetValue = nums[queryIdx];

            std::vector<int>& positions = ourMap[targetValue];

            if (positions.size() == 1) {
                results.push_back(-1);
                continue;
            }

            int minDistance = n;
            auto it = lower_bound(positions.begin(), positions.end(), queryIdx);

            auto right = next(it);
            if (right == positions.end()) right = positions.begin();

            auto left = (it == positions.begin()) ? prev(positions.end()) : prev(it);

            int d1 = abs(queryIdx - *left);
            minDistance = std::min(minDistance, std::min(d1, n - d1));

            int d2 = abs(queryIdx - *right);
            minDistance = std::min(minDistance, std::min(d2, n - d2));

            results.push_back(minDistance);
        }
    return results;
}

int main() {
    std::vector<int> nums = {1, 3, 1, 4, 1, 3, 2};
    std::vector<int> queries = {0, 3, 5};

    std::vector<int> result = solveQueries(nums, queries);

    std::cout << "Results: [ ";
    for (int res : result) {
        std::cout << res << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}