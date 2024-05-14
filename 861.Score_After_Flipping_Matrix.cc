#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int matrixScore(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int row = 0; row < n; ++row) {
            if (grid[row][0] == 0) {
                for (int idx = 0; idx < m; ++idx) {
                    if (grid[row][idx] == 0) {
                        grid[row][idx] = 1;
                    } else {
                        grid[row][idx] = 0;
                    }
                }
            }
        }

        for (auto& row : grid) {
            for (int col = 0; col < row.size(); ++col) {
                std::cout << row[col] << ", ";
            }
            std::cout << "\n";
        }
        std::cout << "--------\n";

        for (int col = 0; col < m; ++col) {
            int zeroCount = 0;
            for (int row = 0; row < n; ++row) {
                if (grid[row][col] == 0) {
                    ++zeroCount;
                }
                if (zeroCount > n/2) break;
            }
            if (zeroCount > n/2) {
                for (int row = 0; row < n; ++row) {
                    if (grid[row][col] == 0) {
                        grid[row][col] = 1;
                    } else {
                        grid[row][col] = 0;
                    }
                }
            }
        }

        for (auto& row : grid) {
            for (int col = 0; col < row.size(); ++col) {
                std::cout << row[col] << ", ";
            }
            std::cout << "\n";
        }
        std::cout << "--------\n";

        int ans = 0;
        for (int row = 0; row < n; ++row) {
            int rowBinary = 0;
            for (int col = 0; col < m; ++col) {
                rowBinary <<= 1;
                rowBinary |= grid[row][col];
            }
            ans += rowBinary;
        }

        std::cout << ans << "\n";
        return ans;
    }
};

/*
    Goal: Flip as many MSBs as possible
    Any row that starts with a 0 should be flipped
    If a column has more 0s than 1s, flip the column
*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    int ans1 = 39;
    std::vector<std::vector<int>> grid2 = {{0}};
    int ans2 = 1;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.matrixScore(grid1) == ans1);
    assert(solution.matrixScore(grid2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}