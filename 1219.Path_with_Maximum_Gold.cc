#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_set>

class Solution {
public:
    std::vector<std::pair<int,int>> directions{
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int dfs(int currRow, int currCol, std::vector<std::vector<int>>& grid, int n, int m) {
        if (currRow < 0 || currRow >= n || currCol < 0 || currCol >= m || grid[currRow][currCol] == 0) return 0;

        int gold = grid[currRow][currCol];
        grid[currRow][currCol] = 0;

        int maxGold = 0;
        for (auto& direction : directions) {
            int newRow = currRow + direction.first;
            int newCol = currCol + direction.second;
            maxGold = std::max(maxGold, dfs(newRow, newCol, grid, n, m));
        }

        grid[currRow][currCol] = gold;

        return maxGold + gold;
    }

    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int maxGold = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                maxGold = std::max(maxGold, dfs(row, col, grid, n, m));
            }
        }

        // std::cout << maxGold << "\n";
        return maxGold;
    }
};
/*

*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{0,6,0},{5,8,7},{0,9,0}};
    int ans1 = 24;
    std::vector<std::vector<int>> grid2 = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    int ans2 = 28;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.getMaximumGold(grid1) == ans1);
    assert(solution.getMaximumGold(grid2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}