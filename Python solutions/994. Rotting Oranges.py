from typing import List
from collections import deque
# Inefficient DFS approach
# class Solution:
#     def __init__(self):
#         self.directions = [
#             [1,0],
#             [-1,0],
#             [0,1],
#             [0,-1]
#         ]

#     def orangesRotting(self, grid: List[List[int]]) -> int:
#         m = len(grid)
#         n = len(grid[0])
#         minutesPassed = 0
#         fresh_count = 0

#         # Initial scan to check if there are any fresh oranges or if it's impossible to rot all
#         for row in grid:
#             for value in row:
#                 if value == 1:
#                     fresh_count += 1

#         if fresh_count == 0:  # No fresh oranges from the start
#             return 0

#         def dfs(row: int, col: int) -> None:
#             if row < 0 or row >= m or col < 0 or col >= n or grid[row][col] != 1:
#                 return

#             grid[row][col] = 3  # Mark orange as to be rotted
#             for direction in self.directions:
#                 newRow, newCol = row + direction[0], col + direction[1]
#                 dfs(newRow, newCol)

#         while fresh_count > 0:
#             oranges_to_rot = 0
#             for rowIdx in range(m):
#                 for colIdx in range(n):
#                     if grid[rowIdx][colIdx] == 2:
#                         for direction in self.directions:
#                             newRow, newCol = rowIdx + direction[0], colIdx + direction[1]
#                             if 0 <= newRow < m and 0 <= newCol < n and grid[newRow][newCol] == 1:
#                                 grid[newRow][newCol] = 3
#                                 oranges_to_rot += 1
            
#             if oranges_to_rot == 0:  # No new oranges rotted this minute, so it's stuck
#                 return -1

#             # Rot the oranges marked to rot in this iteration
#             for rowIdx in range(m):
#                 for colIdx in range(n):
#                     if grid[rowIdx][colIdx] == 3:
#                         grid[rowIdx][colIdx] = 2
#                         fresh_count -= 1

#             minutesPassed += 1

#         return minutesPassed

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        # number of rows
        rows = len(grid)
        if rows == 0:  # check if grid is empty
            return -1
        
        # number of columns
        cols = len(grid[0])
        
        # keep track of fresh oranges
        fresh_cnt = 0
        
        # queue with rotten oranges (for BFS)
        rotten = deque()
        
        # visit each cell in the grid
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    # add the rotten orange coordinates to the queue
                    rotten.append((r, c))
                elif grid[r][c] == 1:
                    # update fresh oranges count
                    fresh_cnt += 1
        
        # keep track of minutes passed.
        minutes_passed = 0
        
        # If there are rotten oranges in the queue and there are still fresh oranges in the grid keep looping
        while rotten and fresh_cnt > 0:

            # update the number of minutes passed
            # it is safe to update the minutes by 1, since we visit oranges level by level in BFS traversal.
            minutes_passed += 1
            
            # process rotten oranges on the current level
            for _ in range(len(rotten)):
                x, y = rotten.popleft()
                
                # visit all the adjacent cells
                for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                    # calculate the coordinates of the adjacent cell
                    xx, yy = x + dx, y + dy
                    # ignore the cell if it is out of the grid boundary
                    if xx < 0 or xx == rows or yy < 0 or yy == cols:
                        continue
                    # ignore the cell if it is empty '0' or visited before '2'
                    if grid[xx][yy] == 0 or grid[xx][yy] == 2:
                        continue
                        
                    # update the fresh oranges count
                    fresh_cnt -= 1
                    
                    # mark the current fresh orange as rotten
                    grid[xx][yy] = 2
                    
                    # add the current rotten to the queue
                    rotten.append((xx, yy))

        
        # return the number of minutes taken to make all the fresh oranges to be rotten
        # return -1 if there are fresh oranges left in the grid (there were no adjacent rotten oranges to make them rotten)
        return minutes_passed if fresh_cnt == 0 else -1


grid1 = [[2,1,1],[1,1,0],[0,1,1]]
ans1 = 4
assert Solution().orangesRotting(grid1) == ans1, "Test failed!"

grid2 = [[2,1,1],[0,1,1],[1,0,1]]
ans2 = -1
assert Solution().orangesRotting(grid2) == ans2, "Test failed!"

grid3 = [[0,2]]
ans3 = 0
assert Solution().orangesRotting(grid3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")