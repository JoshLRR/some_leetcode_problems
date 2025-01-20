#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class Solution {
public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
        std::queue<std::array<int, 2>> q;
        std::array<int, 5> directions = {1, 0, -1, 0, 1};
        int n = grid.size();

        for (int idx = 0; idx < n; ++idx) {
            for (int jdx = 0; jdx < n; ++jdx) {
                if (grid[idx][jdx]) {
                    q.push({idx, jdx});
                }
            }
        }

        while (!q.empty()) {
            auto [idx, jdx] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = idx + directions[d];
                int y = jdx + directions[d + 1];
                if (std::min(x, y) >= 0 && std::max(x, y) < n && grid[x][y] == 0) {
                    grid[x][y] = grid[idx][jdx] + 1;
                    q.push({x, y});
                }
            }
        }

        std::priority_queue<std::array<int, 3>> pq;
        pq.push({grid[0][0], 0, 0});

        while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
            auto [sf, idx, jdx] = pq.top();
            pq.pop();
            for (int d = 0; d < 4; ++d) {
                int x = idx + directions[d];
                int y = jdx + directions[d + 1];
                if (std::min(x, y) >= 0 && std::max(x, y) < n && grid[x][y] > 0) {
                    pq.push({std::min(sf, grid[x][y]), x, y});
                    grid[x][y] *= -1;
                }
            }
        }

        return pq.top()[0] - 1;
    }
};


/*

*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{1,0,0},{0,0,0},{0,0,1}};
    int ans1 = 0;
    std::vector<std::vector<int>> grid2 = {{0,0,1}, {0,0,0}, {0,0,0}};
    int ans2 = 2;
    std::vector<std::vector<int>> grid3 = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
    int ans3 = 2;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.maximumSafenessFactor(grid1) == ans1);
    assert(solution.maximumSafenessFactor(grid2) == ans2);
    assert(solution.maximumSafenessFactor(grid3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}