#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
    int n = grid.size();

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
        return 0;
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(n, - 1));
    std::queue<std::pair<int, int>> q;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 1) {
                q.push({r, c});
                dist[r][c] = 0;
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
        }
    }

    std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        pq.push({dist[0][0], {0, 0}});
        visited[0][0] = true;

        while (!pq.empty()) {
            auto [safeness, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            // If we reached the destination, this is our maximum safeness factor
            if (r == n - 1 && c == n - 1) {
                return safeness;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The safeness of the path to the neighbor is limited by the weakest link
                    int next_safeness = std::min(safeness, dist[nr][nc]);
                    pq.push({next_safeness, {nr, nc}});
                }
            }
        }

        return 0;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0}
    };

    int result = maximumSafenessFactor(grid);

    std::cout << "Maximum Safeness Factor: " << result << std::endl;

    return 0;
}