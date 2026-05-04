#include <iostream>
#include <vector>
#include <climits>

#include <cmath>
int solution(std::vector<int> &A) {
    long long totalSum = 0, LeftSum = 0, RightSum = 0, currentDifference = 0;
    long long minDifference = LLONG_MAX;
    for (size_t i = 0; i < A.size(); i++) {
        totalSum = totalSum + A[i];
    }
    for (size_t i = 0; i < A.size() - 1; i++) {
        LeftSum = LeftSum + A[i];
        RightSum = totalSum - LeftSum;
        currentDifference = (LeftSum > RightSum) ? (LeftSum - RightSum) : (RightSum - LeftSum);
        if (currentDifference < minDifference) {
            minDifference = currentDifference;
        }
    }
    return (int)minDifference;
 }

int main() {
    std::vector<int> A = {3, 1, 2, 4, 3};

    int result = solution(A);

    std::cout << "The minimal difference is: " << result << std::endl;

    return 0;
}