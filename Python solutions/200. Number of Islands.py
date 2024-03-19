from typing import List

class Solution:
    def __init__(self):
        self.directions = [
            [1,0],
            [-1,0],
            [0, 1],
            [0,-1]
        ]

    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        m = len(grid)
        n = len(grid[0])
        count = 0

        def dfs(row: int, col: int) -> None:
            if row < 0 or row >= m or col < 0 or col >= n or (row, col) in visited or grid[row][col] == "0":
                return

            visited.add((row, col))

            for direction in self.directions:
                dfs(row + direction[0], col + direction[1])

        for row_idx, row in enumerate(grid):
            for col_idx, cell in enumerate(row):
                if cell == "1" and (row_idx, col_idx) not in visited:
                    dfs(row_idx, col_idx)
                    count += 1

        return count

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n");