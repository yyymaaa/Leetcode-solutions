#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>

int minScore(int n, std::vector<std::vector<int>>& roads) {
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);

    for (const auto& road : roads) {
        int u = road[0];
        int v = road[1];
        int dist = road[2];
        adj[u].push_back({v, dist}); 
        adj[v].push_back({u, dist});
    }

    int minScore = std::numeric_limits<int>::max();
    std::vector<bool> visited(n + 1, false);

    std::queue<int> q;
    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
      int currentNode = q.front();
      q.pop();

      for (const auto& edge : adj[currentNode]) {
        int neighbor = edge.first;
        int roadDistance = edge.second;

        minScore = std::min(minScore, roadDistance);

        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
      }
    }
    return minScore;
}

int main() {
    std::vector<std::vector<int>> roads1 = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    std::cout << "Test 1: " << minScore(4, roads1) << std::endl;

    std::vector<std::vector<int>> roads2 = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
    std::cout << "Test 2: " << minScore(4, roads2) << std::endl;

    return 0;
}