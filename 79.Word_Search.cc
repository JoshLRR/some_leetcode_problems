#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool dfs(int currRow, int currCol, std::vector<std::vector<char>>& board, std::string& currCombo, const std::string& targetWord, std::vector<std::vector<bool>>& visited) {
        // In-border check and check if cell is already visited
        if (currRow < 0 || currRow >= board.size() || currCol < 0 || currCol >= board[0].size() || visited[currRow][currCol]) {
            return false;
        }

        currCombo += board[currRow][currCol];
        visited[currRow][currCol] = true; // Mark the cell as visited

        // Base Case
        if (currCombo == targetWord) {
            return true;
        }

        // Recursive Case -- check all directions
        std::vector<std::pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (auto& direction : directions) {
            int newRow = currRow + direction.first;
            int newCol = currCol + direction.second;
            if (dfs(newRow, newCol, board, currCombo, targetWord, visited)) {
                return true;
            }
        }

        // Backtracking
        currCombo.pop_back();
        visited[currRow][currCol] = false;
        
        return false;
    }

    bool exist(std::vector<std::vector<char>> board, const std::string& word) {
        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
        std::string currCombo = "";
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (word[0] == board[i][j]) {
                    if (dfs(i, j, board, currCombo, word, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    assert(solution.exist({{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}}, "ABCCED") == true);
    assert(solution.exist({{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}}, "SEE") == true);
    assert(solution.exist({{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}}, "ABCB") == false);

    std::cout << "All tests passed!";
    return 0;
}
