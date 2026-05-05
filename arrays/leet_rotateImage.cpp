#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
               std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            int start = 0;
            int end = n - 1;
            while (start < end) {
                std::swap(matrix[i][start], matrix[i][end]);
                start++;
                end--;
            }
        }
    }

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}, 
        {7, 8, 9}  
    };
    rotate(matrix);
    printMatrix(matrix);

    return 0;
}