#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> prevRow = grid[0];
        std::pair<int,int> prevMin = {INT_MAX, -1};
        std::pair<int,int> prevSecondMin = {INT_MAX, -1};
        
        for (int i = 0; i < n; ++i) {
            if (prevRow[i] < prevMin.first) {
                prevMin.first = prevRow[i];
                prevMin.second = i;
            } else if (prevRow[i] < prevSecondMin.first && prevRow[i] >= prevMin.first) {
                prevSecondMin.first = prevRow[i];
                prevSecondMin.second = i;
            }
        }

        // std::cout << prevMin.first << ", " << prevMin.second << " : " << prevSecondMin.first << ", " << prevSecondMin.second << "\n";
        for (int i = 1; i < n; ++i) {
            std::vector<int> currentRow = grid[i];
            std::pair<int, int> minCandidate = {INT_MAX, -1};
            std::pair<int, int> secondMinCandidate = {INT_MAX, -1};
            
            for (int j = 0; j < n; ++j) {
                if (j != prevMin.second) {
                    currentRow[j] += prevMin.first;
                } else {
                    currentRow[j] += prevSecondMin.first;
                }

                // Update minCandidate and secondMinCandidate for the next row
                if (currentRow[j] < minCandidate.first) {
                    secondMinCandidate = minCandidate;
                    minCandidate = {currentRow[j], j};
                } else if (currentRow[j] < secondMinCandidate.first) {
                    secondMinCandidate = {currentRow[j], j};
                }
            }

            // Update prevRow and min values for the next iteration
            prevRow = currentRow;
            prevMin = minCandidate;
            prevSecondMin = secondMinCandidate;
        }

        for (auto& val : prevRow) {
            std::cout << val << ", ";
        }
        std::cout << "\n";

        return *std::min_element(prevRow.begin(), prevRow.end());
    }
};
/*
    Dynamic Programming -- 

    This solution is slightly optimized for space by keeping track of only the previous row instead of using a table of n*n size to keep track of all cells.
    It can be optimized further to O(1) space by getting rid of the previous row tracking and only keeping track of the two previous mins

    Keep track of two minimums of the previous row
    For each cell in the current row, add the minimum unless the previous min is from the same column. Otherwise, add the second minimum since it's guaranteed to be from another column
    
    Return the minimum value of the final iteration of prevRow

*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid1 = {{1,2,3}, {4,5,6}, {7,8,9}};
    int ans1 = 13;
    std::vector<std::vector<int>> grid2 = {{7}};
    int ans2 = 7;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.minFallingPathSum(grid1) == ans1);
    assert(solution.minFallingPathSum(grid2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}