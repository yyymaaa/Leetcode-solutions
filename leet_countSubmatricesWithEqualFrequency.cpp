#include <vector>
#include <string>
#include <iostream>


int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int matCount = 0;

    std::vector<std::vector<int>> prefixX(m, std::vector<int>(n, 0));
    std::vector<std::vector<int>> prefixY(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int aboveX = (i > 0) ? prefixX[i - 1][j] : 0;
            int leftX  = (j > 0) ? prefixX[i][j - 1] : 0;
            int diagX  = (i > 0 && j > 0) ? prefixX[i - 1][j - 1] : 0;

            int aboveY = (i > 0) ? prefixY[i - 1][j] : 0;
            int leftY  = (j > 0) ? prefixY[i][j - 1] : 0;
            int diagY  = (i > 0 && j > 0) ? prefixY[i - 1][j - 1] : 0;

                // Calculate current prefix counts
           prefixX[i][j] = aboveX + leftX - diagX + (grid[i][j] == 'X' ? 1 : 0);
           prefixY[i][j] = aboveY + leftY - diagY + (grid[i][j] == 'Y' ? 1 : 0);

                // Condition check: Equal frequency AND at least one 'X'
            if (prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0) {
            matCount++;
            }
        }
    }

    return matCount;
}

int main() {
    std::vector<std::vector<char>> grid = {
        {'X', 'Y', '.'},
        {'Y', '.', '.'}
    };

    int result = numberOfSubmatrices(grid);

    std::cout << "Number of valid submatrices: " << result << std::endl;

    std::vector<std::vector<char>> grid2 = {
        {'X', 'X'},
        {'X', 'Y'}
    };
    std::cout << "\nTest Case 2: " << numberOfSubmatrices(grid2) << std::endl;

    return 0;
}