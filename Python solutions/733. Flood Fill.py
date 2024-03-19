from typing import List

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        originalColor = image[sr][sc]
        if originalColor == color: return image

        directions = [
            (1, 0),
            (-1, 0),
            (0, 1),
            (0, -1)
        ]

        def dfs(row: int, col: int):
            if (row < 0 or row >= m or col < 0 or col >= n or image[row][col] != originalColor):
                return
            image[row][col] = color
            for dRow, dCol in directions:
                dfs(row + dRow, col + dCol)

        dfs(sr, sc)
        return image

image1 = [[1,1,1],[1,1,0],[1,0,1]]
sr1 = 1
sc1 = 1
color1 = 2
ans1 = [[2,2,2],[2,2,0],[2,0,1]]
assert Solution().floodFill(image1,sr1,sc1,color1) == ans1, "Test failed!"

image1 = [[0,0,0],[0,0,0]]
sr1 = 0
sc1 = 0
color1 = 0
ans1 = [[0,0,0],[0,0,0]]
assert Solution().floodFill(image1,sr1,sc1,color1) == ans1, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")