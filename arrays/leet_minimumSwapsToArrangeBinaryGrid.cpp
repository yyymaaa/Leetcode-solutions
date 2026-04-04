#include <iostream>
#include <vector>
#include <algorithm>

int minSwaps(std::vector<std::vector<int>>& grid) {
    std::vector<int> trailingZeros;
    int n = grid.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailingZeros.push_back(count);
    }


    int totalSwaps = 0;

    for (int i = 0; i < n; i++) {
        int target = n - 1 - i;
        int foundIdx = -1;

        for (int j = i; j < n; j++) {
            if (trailingZeros[j] >= target) {
                foundIdx = j;
                break;
            }
        }

        if (foundIdx == -1) return -1;

        for (int j = foundIdx; j > i; j--) {
            std::swap(trailingZeros[j], trailingZeros[j - 1]);
            totalSwaps++;
        }
    }
    return totalSwaps;
}

int main() {
    std::vector<std::vector<int>> grid1 = {
        {0, 0, 1},
        {1, 1, 0},
        {1, 0, 0}
    };

    std::vector<std::vector<int>> grid2 = {
    {0,1,1,0}, 
    {0,1,1,0}, 
    {0,1,1,0}, 
    {0,1,1,0}
    };

    int result = minSwaps(grid1);
    int result2 = minSwaps(grid2);

 
    std::cout << "Minimum swaps needed for grid 1: " << result << std::endl;
    std::cout << "Minimum swaps needed for grid 2: " << result2 << std::endl;
   

    return 0;
}