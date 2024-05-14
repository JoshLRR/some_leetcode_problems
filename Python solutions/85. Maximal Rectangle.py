import time
from typing import List

class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        
        n = len(matrix[0])
        heights = [0] * (n + 1)
        max_area = 0

        for row in matrix:
            for i in range(n):
                heights[i] = heights[i] + 1 if row[i] == "1" else 0
            
            stack = [-1]
            for i in range(n + 1):
                while heights[i] < heights[stack[-1]]:
                    h = heights[stack.pop()]
                    w = i - stack[-1] - 1
                    max_area = max(max_area, h * w)
                
                stack.append(i)
        
        return max_area
    
"""
    Brute Force --
    Iterate through each cell, check to see if it's the top left of a rectangle
    If we find a 1-cell, check how long the row goes for
    Go down a row, see if it goes as far as the previous. If not, we adjust the size of the current rectangle's row size
"""

matrix1 = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
ans1 = 6
matrix2 = [["0"]]
ans2 = 0
matrix3 = [["1"]]
ans3 = 1
t0 = time.time()
assert Solution().maximalRectangle(matrix1) == ans1, "Test failed!"
assert Solution().maximalRectangle(matrix2) == ans2, "Test failed!"
assert Solution().maximalRectangle(matrix3) == ans3, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")