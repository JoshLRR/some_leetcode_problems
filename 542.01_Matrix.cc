#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        std::queue<std::pair<int,int>> oneQueue;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (mat[row][col] != 0) {
                    oneQueue.push({row, col});
                }
            }
        }

        while (!oneQueue.empty()) {
            std::pair<int, int> temp = oneQueue.front();
            oneQueue.pop();
        }

        return {};
    }
};

/*
    BFS through the cells
    If a cell has a 1, add the coordinates to a queue
    After pre-processing the matrix
*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> mat1 = {{0,0,0}, {0,1,0}, {0,0,0}};
    std::vector<std::vector<int>> ans1 = {{0,0,0}, {0,1,0}, {0,0,0}};

    std::vector<std::vector<int>> mat2 = {{0,0,0}, {0,1,0}, {1,1,1}};
    std::vector<std::vector<int>> ans2 = {{0,0,0}, {0,1,0}, {1,2,1}};

    auto t0 = std::chrono::high_resolution_clock::now();
    // std::vector<std::vector<int>> test1 = solution.updateMatrix(mat1);
    std::vector<std::vector<int>> test2 = solution.updateMatrix(mat2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    // assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}