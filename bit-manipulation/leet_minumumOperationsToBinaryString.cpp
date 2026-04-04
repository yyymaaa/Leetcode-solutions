#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>

int minOperations(std::string s, int k) {
        int n = s.size();
        int initialZeros = 0;
        
        // 1. We only care about the count of '0's
        // nodeSets[0] stores even counts, nodeSets[1] stores odd counts
        std::vector<std::set<int>> nodeSets(2);
        for (int i = 0; i <= n; i++) {
            nodeSets[i % 2].insert(i);
        }

        for (char c : s) {
            if (c == '0') initialZeros++;
        }

        // 2. BFS Setup
        std::vector<int> dist(n + 1, INT_MAX);
        std::queue<int> q;

        dist[initialZeros] = 0;
        q.push(initialZeros);
        nodeSets[initialZeros % 2].erase(initialZeros);

        while (!q.empty()) {
            int m = q.front();
            q.pop();

            if (m == 0) return dist[0];

            // 3. Math to find the reachable range of zeros after one flip
            // c1: min zeros we MUST flip, c2: max zeros we CAN flip
            int c1 = std::max(k - (n - m), 0); 
            int c2 = std::min(m, k);

            // The new number of zeros will be between lnode and rnode
            int lnode = m + k - 2 * c2;
            int rnode = m + k - 2 * c1;

            auto& currentSet = nodeSets[lnode % 2];
            
            // 4. Use lower_bound to jump only to unvisited valid states
            for (auto it = currentSet.lower_bound(lnode); it != currentSet.end() && *it <= rnode; ) {
                int nextM = *it;
                dist[nextM] = dist[m] + 1;
                q.push(nextM);
                
                // Erase to mark as visited and increment iterator
                it = currentSet.erase(it); 
            }
        }

        return (dist[0] == INT_MAX) ? -1 : dist[0];
    }
    
int main() {
    std::cout << "Result: " << minOperations("0101", 3) << std::endl;
    std::cout << "Result 2: " << minOperations("110000000000000", 9) << std::endl;
    return 0;
}