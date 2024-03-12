#include <iostream>
#include <cassert>
#include <vector>
#include <map>
class Solution {
public:
    int n;
    int m;
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        std::vector<std::vector<int>> ans;
        std::map<std::pair<int,int>, bool> canReachPacific;
        std::map<std::pair<int,int>, bool> canReachAtlantic;
        n = heights.size();
        m = heights[0].size();
        
        // Iterate through all border nodes
        for (int i = 0; i < m; ++i) {
            dfs(0,i,INT_MIN,heights, canReachPacific);
            dfs(n-1,i,INT_MIN,heights, canReachAtlantic);
        }

        for (int i = 0; i < n; ++i) {
            dfs(i, 0, INT_MIN,heights, canReachPacific);
            dfs(i, m-1, INT_MIN,heights, canReachAtlantic);
        }

        for (auto& cell : canReachPacific) {
            if (canReachAtlantic.count(cell.first)) {
                ans.push_back({cell.first.first, cell.first.second});
            }
        }
        for (auto& cell : ans) {
            std::cout << cell[0] << ":" << cell[1] << "\n";
        }
        std::cout << "-----\n";
        return ans;
    }
    void dfs(int row, int col, int prevHeight, std::vector<std::vector<int>>& heights, std::map<std::pair<int,int>, bool>& visited) {
        if (row < 0 || row >= n || col < 0 || col >= m || prevHeight > heights[row][col] || visited[{row,col}]) {
            return;
        }

        visited[{row, col}] = true;
        for (auto& direction : directions) {
            dfs(row + direction[0], col + direction[1], heights[row][col], heights, visited);
        }
    }
private:
    std::vector<std::vector<int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0,-1}
    };
};
/*
    DFS
    List to keep track of cells that can reach Pacific Ocean (top and left sides)
    List to keep track of cells that can reach Atlantic Ocean (right and bottom sides)
    Call dfs function on all border nodes, they're guaranteed to reach one and will cut through any peak nodes anyway on the way to check the other ocean.
*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> heights1 = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    std::vector<std::vector<int>> ans1 = {{0,4}, {1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};
    assert(solution.pacificAtlantic(heights1) == ans1);

    std::vector<std::vector<int>> heights2 = {{1}};
    std::vector<std::vector<int>> ans2 = {{0,0}};
    assert(solution.pacificAtlantic(heights2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}