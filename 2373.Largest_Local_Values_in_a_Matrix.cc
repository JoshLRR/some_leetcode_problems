#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> ans(n - 2, std::vector<int>(n - 2, 0));
        
        for (int row = 1; row < n - 1; ++row) {
            for (int col = 1; col < n - 1; ++col) {
                int maxSoFar = INT_MIN;
                for (int idx = row - 1; idx <= row + 1; ++idx) {
                    for (int jdx = col - 1; jdx <= col + 1; ++jdx) {
                        maxSoFar = std::max(maxSoFar, grid[idx][jdx]);
                    }
                }

                ans[row - 1][col - 1] = maxSoFar;
            }
        }

        return ans;
    }
};
/*

*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    std::vector<std::vector<int>> ans1 = {{9,9}, {8,6}};
    std::vector<std::vector<int>> grid2 = {{1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    std::vector<std::vector<int>> ans2 = {{2,2,2}, {2,2,2}, {2,2,2}};
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.largestLocal(grid1) == ans1);
    assert(solution.largestLocal(grid2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}