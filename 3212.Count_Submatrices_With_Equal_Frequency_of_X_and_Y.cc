#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        std::vector<std::vector<int>> X(n + 1, std::vector<int>(m + 1));
        std::vector<std::vector<int>> Y(n + 1, std::vector<int>(m + 1));

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                X[row + 1][col + 1] = X[row][col + 1] + X[row + 1][col] - X[row][col] + (grid[row][col] == 'X');
                Y[row + 1][col + 1] = Y[row + 1][col] + Y[row][col + 1] - Y[row][col] + (grid[row][col] == 'Y');

                if (X[row + 1][col + 1] == Y[row + 1][col + 1] && X[row + 1][col + 1] > 0) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<std::vector<char>> grid1 = {{'X', 'Y', '.'}, {'Y', '.','.'}};
    int ans1 = 3;

    std::vector<std::vector<char>> grid2 = {{'X', 'X'}, {'X', 'Y'}};
    int ans2 = 0;

    std::vector<std::vector<char>> grid3 = {{'.', '.'}, {'.','.'}};
    int ans3 = 0;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.numberOfSubmatrices(grid1);
    // int test2 = solution.numberOfSubmatrices(grid2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    // assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}