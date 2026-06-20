#include <iostream>
#include <vector>
#include <algorithm>

int maxBuilding(int n, std::vector<std::vector<int>>& restrictions) {
    restrictions.push_back({1, 0});
    std::sort(restrictions.begin(), restrictions.end());
    if (restrictions.back()[0] != n) {
        restrictions.push_back({n, n - 1});
    }
    
    int m = restrictions.size();
    for (int i = 1; i < m; i++) {
        int dist = restrictions[i][0] - restrictions[i-1][0];
        int max_reach = restrictions[i-1][1] + dist;
        restrictions[i][1] = std::min(restrictions[i][1], max_reach);
    }
    for (int i = m - 2; i >= 0; i--) {
        int dist = restrictions[i+1][0] - restrictions[i][0];
        int max_reach = restrictions[i+1][1] + dist;
        restrictions[i][1] = std::min(restrictions[i][1], max_reach);
    }
    
    int max_height = 0;
    for (int i = 0; i < m - 1; i++) {
        int id1 = restrictions[i][0], h1 = restrictions[i][1];
        int id2 = restrictions[i+1][0], h2 = restrictions[i+1][1];
        int peak = (h1 + h2 + (id2 - id1)) / 2;
        max_height = std::max(max_height, peak);
    }
    return max_height;
}

int main() {
    int n1 = 5;
    std::vector<std::vector<int>> restrictions1 = {{2, 1}, {4, 1}};
    std::cout << "Test 1: " << maxBuilding(n1, restrictions1) << std::endl;

    int n2 = 6;
    std::vector<std::vector<int>> restrictions2 = {};
    std::cout << "Test 2: " << maxBuilding(n2, restrictions2) << std::endl;

    int n3 = 10;
    std::vector<std::vector<int>> restrictions3 = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
    std::cout << "Test 3: " << maxBuilding(n3, restrictions3) << std::endl;

    return 0;
}