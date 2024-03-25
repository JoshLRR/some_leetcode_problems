from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Row Validation
        for i in range(9):
            seen = set()
            for j in range(9):
                currChar = board[i][j]
                # print(currChar, end = " ")
                if currChar == ".":
                    pass
                else:
                    if currChar in seen:
                        return False
                    else:
                        seen.add(currChar)

        # Column Validation
        for i in range(9):
            seen = set()
            for j in range(9):
                currChar = board[j][i]
                # print(currChar, end = " ")
                if currChar == ".":
                    pass
                else:
                    if currChar in seen:
                        return False
                    else:
                        seen.add(currChar)

        
        for i in range(3):
            for j in range(3):
                seen = set()

                for ii in range(3):
                    for jj in range(3):
                        currChar = board[i * 3 + ii][j * 3 + jj]
                        if currChar == ".":
                            pass
                        else:
                            if currChar in seen:
                                return False
                            else:
                                seen.add(currChar)
        
        return True

"""
    Check each row for validity
    Check each col for validity
    Check each 3x3 square for validty

"""

board1 = [["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
assert Solution().isValidSudoku(board1) == True, "Test failed!"

board2 = [["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
assert Solution().isValidSudoku(board2) == False, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")