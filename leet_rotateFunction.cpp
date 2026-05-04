#include <iostream>
#include <vector>
#include <algorithm>

int maxRotateFunction(std::vector<int>& nums) {
    long long totalArrSum = 0;
    int n = nums.size();
    long long currentF = 0;

    for (int i = 0; i < n; i ++) {
        totalArrSum += nums[i];
        currentF += (long long)i * nums[i];
    }

    long long max_val = currentF;

    for (int i = 1; i < n; i ++) {
        int rotating = nums[n-i];
        long long nextF = currentF + totalArrSum - ((long long)n * rotating);
        if (nextF > max_val) {
           max_val = nextF;
        }
        currentF = nextF;
    }

    return max_val;
}

int main() {
    
    std::vector<int> nums1 = {4, 3, 2, 6};
    std::cout << "Example 1 Output: " << maxRotateFunction(nums1) << std::endl;

    std::vector<int> nums2 = {100};
    std::cout << "Example 2 Output: " << maxRotateFunction(nums2) << std::endl;

    return 0;
}