#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

class Solution {
private:
    std::vector<std::vector<int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    int n = 0;
    int m = 0;
public:
    void dfs(int row, int col, std::vector<std::vector<bool>>& visited, std::vector<std::vector<char>>& grid) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0' || visited[row][col]) {
            return;
        }

        visited[row][col] = true;;
        for (auto& direction: directions) {
            dfs(row + direction[0], col + direction[1], visited,grid);
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        std::vector<std::vector<bool>> visited(m , std::vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid);
                    ++count;
                }
            }
        }

        std::cout << count << "\n";
        return count;
    }

};

/*
    Flood-Fill algorithm:
    Use DFS on all cells. If a cell is 0, can return immediately
    Whenever a 1 is spotted, add the cell (row,col) to a visited set and call dfs on it.
        Note: Unordered_set of pairs doesn't work without a custom hash function
    Explore all adjacent cells to see if they are also 1, add those cells to visited

    Time Complexity -- O(m*n)
*/

int main() {
    Solution solution;
    std::vector<std::vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    int ans1 = 1;
    assert(solution.numIslands(grid1) == ans1);

    std::vector<std::vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int ans2 = 3;
    assert(solution.numIslands(grid2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}