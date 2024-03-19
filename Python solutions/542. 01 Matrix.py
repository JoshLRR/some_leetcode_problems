from typing import List
class Solution:
    def __init__(self):
        self.directions = [
            [1, 0],
            [-1,0],
            [0, 1],
            [0 -1]
        ]
        
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])

        dpTable = [[0 for _ in range(m)] for _ in range(n)]

        for row in range(n):
            for col in range(m):
                if mat[row][col] == 1:
                    for direction in self.directions:
                        newRow = row + direction[0]
                        newCol = col + direction[1]
                        if (newRow < 0 or newRow >= n or newCol < 0 or newCol >= 0): pass
                        dpTable[row][col] = max(1 + dpTable[row + direction[0]][col + direction[1]], dpTable[row][col])
        
        print(dpTable)
        return dpTable



mat1 = [[0,0,0],[0,1,0],[0,0,0]]
ans1 = [[0,0,0],[0,1,0],[0,0,0]]
assert Solution().updateMatrix(mat1) == ans1, "Test failed!"

mat2 = [[0,0,0],[0,1,0],[1,1,1]]
ans2 = [[0,0,0],[0,1,0],[1,2,1]]
assert Solution().updateMatrix(mat2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")