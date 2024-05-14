#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        std::vector<std::vector<int>> ans;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (land[row][col] == 1) {                    
                    int newRow = row;
                    while (newRow + 1 < m && land[newRow + 1][col] == 1) {
                        ++newRow;
                    }

                    int newCol = col;
                    while (newCol + 1 < n && land[newRow][newCol + 1] == 1) {
                        ++newCol;
                    }
                    
                    for (int i = row; i <= newRow; ++i) {
                        for (int j = col; j <= newCol; ++j) {
                            land[i][j] = 0;
                        }
                    }

                    ans.push_back({row, col, newRow, newCol});
                }
            }
        }

        return ans;
    }
};

/*
    Iterate through each cell -- if we find a one, assume it's the top left of a rectangle
    Keep iterating through rows and cells until a 0 or a boundary is found, that's an edge
    After doing this for both rows and cells, we'll be at the bottom right of the square

    Mark all cells in that rectangle as 0 to mark them as visited
*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> land1 = {{1,0,0},{0,1,1},{0,1,1}};
    std::vector<std::vector<int>> ans1 = {{0,0,0,0}, {1,1,2,2}};
    std::vector<std::vector<int>> land2 = {{1,1}, {1,1}};
    std::vector<std::vector<int>> ans2 = {{0,0,1,1}};
    std::vector<std::vector<int>> land3 = {{0}};
    std::vector<std::vector<int>> ans3 = {};
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.findFarmland(land1) == ans1);
    assert(solution.findFarmland(land2) == ans2);
    assert(solution.findFarmland(land3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}