#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeHighDefinitionIntervals(std::vector<std::vector<int>> intervals) {
    if (intervals.empty()) return {};
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> merged;
    for (const auto& interval : intervals) {
        if (merged.empty() || interval[0] > merged.back()[1]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = std::max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}

int main() {
    std::vector<std::vector<int>> input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    std::vector<std::vector<int>> result = mergeHighDefinitionIntervals(input);

    std::cout << "Merged Intervals: " << std::endl;
    for (const auto& pair : result) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}