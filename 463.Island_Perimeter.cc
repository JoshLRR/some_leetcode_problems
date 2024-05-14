#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int perimeter = 0;

        std::vector<std::vector<int>> directions {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    int addedPerim = 4;
                    for (auto& direction : directions) {
                        int newRow = row + direction[0];
                        int newCol = col + direction[1];
                        if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                            --addedPerim;
                        }
                    }
                    perimeter += addedPerim;
                    std::cout << "Adding: " << addedPerim << " Perimeter now at: " << perimeter << "\n";
                }
            }
        }

        std::cout << perimeter << "\n";
        return perimeter;
    }
};

/*
    Just iterate through each cell and if a cell is 1, check for neighbors. 
    Start with potentially adding 4 to the perimeter count, for each neighbor subtract 1
*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int ans1 = 16;
    std::vector<std::vector<int>> grid2 = {{1}};
    int ans2 = 4;
    std::vector<std::vector<int>> grid3 = {{1,0}};
    int ans3 = 4;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.islandPerimeter(grid1) == ans1);
    assert(solution.islandPerimeter(grid2) == ans2);
    assert(solution.islandPerimeter(grid3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}