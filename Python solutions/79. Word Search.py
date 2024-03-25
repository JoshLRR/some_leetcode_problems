from typing import List

class Solution:
    def __init__(self):
        self.directions = [
            [1,0],
            [-1,0],
            [0,1],
            [0,-1]
        ]

    def exist(self, board: List[List[str]], word: str) -> bool:
        cols = len(board[0])
        rows = len(board)
        
        def dfs(row: int, col: int, idx: int) -> bool:
            if row < 0 or row >= rows or col < 0 or col >= cols or board[row][col] != word[idx]:
                return False

            if idx == len(word) - 1:
                return True
            
            currLetter = board[row][col]
            board[row][col] = "*"

            for direction in self.directions:
                if dfs(row + direction[0], col + direction[1], idx + 1):
                    return True

            board[row][col] = currLetter
            return False

        for row in range(rows):
            for col in range(cols):
                if (word[0] == board[row][col]):
                    if dfs(row, col, 0):
                        return True
        
        return False
        


board1 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word1 = "ABCCED"
assert Solution().exist(board1, word1) == True, "Test failed!"

board2 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word2 = "SEE"
assert Solution().exist(board2, word2) == True, "Test failed!"

board3 = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word3 = "ABCB"
assert Solution().exist(board3, word3) == False, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")