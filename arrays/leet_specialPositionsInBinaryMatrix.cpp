#include <iostream>
#include <vector>
// row = i m
// column = j n
int numSpecial(std::vector<std::vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int specialPosition = 0;
    std::vector<int> rowCount(m, 0);
    std::vector<int> columnCount(n, 0);
    for (int j = 0; j < n; j++) {       
        for (int i = 0; i < m; i++) {   
            rowCount[i] += mat[i][j];
            columnCount[j] += mat[i][j]; 
        }
    }
     for (int j = 0; j < n; j++) {       
        for (int i = 0; i < m; i++) {   
            if (mat[i][j] == 1 && rowCount[i] == 1 && columnCount[j] == 1) {
                specialPosition++;
            } 
        }
    }
    return specialPosition;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {1, 0, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    int result = numSpecial(mat);

    std::cout << "Number of special positions: " << result << std::endl;

    return 0;
}
