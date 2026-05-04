#include <iostream>
#include <vector>

int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int matCount = 0;

    if (grid[0][0] > k) {
        return 0;
    }

    std::vector<std::vector<int>> currentSum(m, std::vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int above = (i > 0) ? currentSum[i-1][j] : 0 ;
            int left = (j > 0) ? currentSum[i][j-1] : 0 ;
            int diagonal = (i > 0 && j > 0) ? currentSum[i-1][j-1] : 0 ;

            currentSum[i][j] = above + left - diagonal + grid[i][j];

             if (currentSum[i][j] <= k) {
                matCount++;
             } else {
                break;
             }

        }
    }
    return matCount;

}

int main() {
    std::vector<std::vector<int>> grid = {
        {7, 2, 9},
        {1, 5, 0},
        {2, 6, 6}
    };
    
    int result = countSubmatrices(grid, 20);

    std::cout << "The result is: " << result << std::endl;
}