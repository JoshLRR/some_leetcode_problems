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

        



mat1 = [[0,0,0],[0,1,0],[0,0,0]]
ans1 = [[0,0,0],[0,1,0],[0,0,0]]
assert Solution().updateMatrix(mat1) == ans1, "Test failed!"

mat2 = [[0,0,0],[0,1,0],[1,1,1]]
ans2 = [[0,0,0],[0,1,0],[1,2,1]]
assert Solution().updateMatrix(mat2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")