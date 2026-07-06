#include <iostream>
#include <vector>
#include <algorithm>

int removeCoveredIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        int remaining_count = 0;
        int max_end = 0;

        for (const auto& interval : intervals) {
            int current_end = interval[1];

            if (current_end > max_end) {
                remaining_count++;
                max_end = current_end;
            }
        }

        return remaining_count;
}

int main() {
    std::vector<std::vector<int>> intervals1 = {{1, 4}, {3, 6}, {2, 8}};
    std::cout << "Remaining intervals (Test 1): " << removeCoveredIntervals(intervals1) << std::endl; // Expected: 2

    std::vector<std::vector<int>> intervals2 = {{1, 4}, {2, 3}};
    std::cout << "Remaining intervals (Test 2): " << removeCoveredIntervals(intervals2) << std::endl; // Expected: 1

    return 0;
}