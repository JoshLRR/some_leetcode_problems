#include <iostream>
#include <cassert>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        std::vector<std::pair<int, int>> directions = {
            // Vertical
            {1, 0},
            {-1, 0},
            // Horizontal
            {0, -1},
            {0, 1},
            // Diagonal
            {-1, -1},
            {-1, 1},
            {1, 1},
            {1, -1}
        };

        int m = board.size();
        int n = board[0].size(); // Ensure we capture n from the board's width

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) { // Use n for consistency
                int neighbors = 0;
                for (auto& direction : directions) {
                    int newRow = row + direction.first;
                    int newCol = col + direction.second;
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                        if (board[newRow][newCol] == 1 || board[newRow][newCol] == 3) {
                            ++neighbors;
                        }
                    }
                }
                // Group conditions properly with parentheses for clarity
                if (board[row][col] == 1 && (neighbors < 2 || neighbors > 3)) {
                    board[row][col] = 3; // Live to dead
                } else if (board[row][col] == 0 && neighbors == 3) {
                    board[row][col] = 4; // Dead to live
                }
            }
        }

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (board[row][col] == 3) {
                    board[row][col] = 0;
                } else if (board[row][col] == 4) {
                    board[row][col] = 1;
                }
            }
        }
    }
};


/*
    To do inline without creating extra data structures, create two additional flags
    3 == previously live and will be changed to dead
    4 == previously dead and will be changed to live

    Extra loop, but keeps memory O(1)
*/

bool boardsEqual(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    if (a.size() != b.size() || a[0].size() != b[0].size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[0].size(); ++j) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main() {
    Solution solution;
    // Test Case 1
    std::vector<std::vector<int>> board1 = {{0,0,0},{0,1,0},{0,0,0}};
    std::vector<std::vector<int>> expected1 = {{0,0,0},{0,0,0},{0,0,0}};
    solution.gameOfLife(board1);
    assert(boardsEqual(board1, expected1));

    // Test Case 2
    std::vector<std::vector<int>> board2 = {{1,1,1},{0,0,0},{0,0,0}};
    std::vector<std::vector<int>> expected2 = {{0,1,0},{0,1,0},{0,0,0}};
    solution.gameOfLife(board2);
    assert(boardsEqual(board2, expected2));

    // Test Case 3 (Blinker)
    std::vector<std::vector<int>> board3 = {{0,0,0,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0}};
    std::vector<std::vector<int>> expected3 = {{0,0,0,0,0},{0,0,0,0,0},{0,1,1,1,0},{0,0,0,0,0},{0,0,0,0,0}};
    solution.gameOfLife(board3);
    assert(boardsEqual(board3, expected3));
    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}