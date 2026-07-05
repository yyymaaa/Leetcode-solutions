#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

    std::vector<int> pathsWithMaxScore(std::vector<std::string>& board) {
        int n = board.size();
        int MOD = 1000000007;

        std::vector<std::vector<int>> max_score(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> path_count(n, std::vector<int>(n, 0));

        path_count[0][0] = 1;

        int dr[] = {-1, 0, -1};
        int dc[] = {0, -1, -1};

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                // Skip the start 'E' and obstacles 'X'
                if (board[r][c] == 'E' || board[r][c] == 'X') {
                    continue;
                }

                int best_prev_score = -1;
                int ways = 0;

                for (int i = 0; i < 3; i++) {
                    int prev_r = r + dr[i];
                    int prev_c = c + dc[i];

                    // Check boundaries and ensure the neighbor is reachable
                    if (prev_r >= 0 && prev_c >= 0 && path_count[prev_r][prev_c] > 0) {
                        if (max_score[prev_r][prev_c] > best_prev_score) {
                            best_prev_score = max_score[prev_r][prev_c];
                            ways = path_count[prev_r][prev_c];
                        } else if (max_score[prev_r][prev_c] == best_prev_score) {
                            ways = (ways + path_count[prev_r][prev_c]) % MOD;
                        }
                    }
                }

                if (best_prev_score != -1) {
                    int current_val = (board[r][c] == 'S') ? 0 : (board[r][c] - '0');
                    max_score[r][c] = best_prev_score + current_val;
                    path_count[r][c] = ways;
                }
            }
        }

        return {max_score[n - 1][n - 1], path_count[n - 1][n - 1]};
    }


int main() {

    std::vector<std::string> board = {"E23", "2X2", "12S"};
    std::vector<int> result = pathsWithMaxScore(board);
    
    std::cout << "Max Score: " << result[0] << ", Path Count: " << result[1] << std::endl;
    return 0;
}