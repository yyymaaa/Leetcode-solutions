#include <iostream>
#include <vector>
#include <numeric>

class DSU {
    public:
        std::vector<int> parent;
        int components;
        DSU(int n) : components(n) {
            parent.resize(n);
            std::iota(parent.begin(), parent.end(), 0);
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
            return false;
        }
};

class Solution {
    bool canAchieve(int X, int n, std::vector<std::vector<int>>& edges, int k) {
        DSU dsu(n);
        int edgesUsed = 0;
        int upgradesUsed = 0;

        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < X) return false;
                if (!dsu.unite(e[0], e[1])) return false;
                edgesUsed++;
            }
        }

        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= X) {
                if (dsu.unite(e[0], e[1])) edgesUsed++;
            }
        }

        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < X && (e[2] * 2) >= X && upgradesUsed < k) {
                if (dsu.unite(e[0], e[1])) {
                    upgradesUsed++;
                    edgesUsed++;
                }
            }
        }
        return edgesUsed == n - 1;
    }
public:
    int maxStability (int n, std::vector<std::vector<int>>& edges, int k) {
        int low = 1, high = 200000, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAchieve(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n1 = 3;
    std::vector<std::vector<int>> edges1 = {{0, 1, 2, 1}, {1, 2, 3, 0}};
    int k1 = 1;
    std::cout << "Example 1 Output: " << sol.maxStability(n1, edges1, k1)  << std::endl;

    int n2 = 3;
    std::vector<std::vector<int>> edges2 = {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}};
    int k2 = 2;
    std::cout << "Example 2 Output: " << sol.maxStability(n2, edges2, k2)  << std::endl;

    int n3 = 3;
    std::vector<std::vector<int>> edges3 = {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}};
    int k3 = 0;
    std::cout << "Example 3 Output: " << sol.maxStability(n3, edges3, k3)  << std::endl;

    return 0;
}