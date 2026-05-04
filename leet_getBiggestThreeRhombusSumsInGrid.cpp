#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> getBiggestThree(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    std::set<int> distinctSums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                distinctSums.insert(grid[i][j]);
                for (int L = 1; i -L >= 0 && i + L < m && j - L >= 0 && j + L < n; L++) {
                    int currentSum = 0;
                    int r = i - L, c = j; // starting at the top corner
                    for (int k = 0; k < L; k++) currentSum += grid[r++][c++];
                    for (int k = 0; k < L; k++) currentSum += grid[r++][c--];
                    for (int k = 0; k < L; k++) currentSum += grid[r--][c--];
                    for (int k = 0; k < L; k++) currentSum += grid[r--][c++];
                  
                    distinctSums.insert(currentSum);
                }
            }
        }

        std::vector<int> result(distinctSums.begin(), distinctSums.end());
        std::reverse(result.begin(), result.end());

        if (result.size() > 3) {
            result.resize(3);
        }
        return result;
    }

int main() {
    std::vector<std::vector<int>> grid = {
        {3, 4, 5, 1, 3},
        {3, 3, 4, 2, 3},
        {20, 30, 200, 40, 10},
        {1, 5, 5, 4, 1},
        {4, 3, 2, 2, 5}
    };

    std::vector<int> topThree = getBiggestThree(grid);

    std::cout << "The biggest three distinct rhombus sums are: ";
    for (int sum : topThree) {
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    return 0;
}