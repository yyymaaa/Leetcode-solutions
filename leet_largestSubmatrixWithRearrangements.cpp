#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int largestSubmatrix(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int maxArea = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && i > 0) {
                matrix[i][j] += matrix[i-1][j];
            } 
        }
        std::vector<int> currentRow = matrix[i];
        std::sort(currentRow.begin(), currentRow.end(), std::greater<int>());
        for (int j = 0; j < n; j++) {
            maxArea = std::max(maxArea, currentRow[j] * (j + 1));
        }

    }

    return maxArea;

}


int main() {

    std::vector<std::vector<int>> matrix1 = {
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 1}
    };
    std::cout << "Test Case 1 Result: " << largestSubmatrix(matrix1) << std::endl;

    std::vector<std::vector<int>> matrix2 = {
        {1, 0, 1, 0, 1}
    };
    std::cout << "Test Case 2 Result: " << largestSubmatrix(matrix2) << std::endl;

    std::vector<std::vector<int>> matrix3 = {
        {0, 0},
        {0, 0}
    };
    std::cout << "Test Case 3 Result: " << largestSubmatrix(matrix3) << std::endl;

    return 0;
}