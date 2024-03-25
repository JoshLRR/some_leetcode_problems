from typing import List

class Solution:
    def __init__(self):
        self.directions = [
            [-1,0],
            [1,0],
            [0,1],
            [0,-1]
        ]

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        ans = []
        rowCount = len(heights)
        colCount = len(heights[0])

        canReachPacificOcean = set()
        canReachAtlanticOcean = set()

        def dfs(row: int, col: int, prevHeight: int, visited: set):
            if row < 0 or row >= rowCount or col < 0 or col >= colCount or heights[row][col] < prevHeight or (row,col) in visited:
                return

            visited.add((row,col))

            for direction in self.directions:
                newRow = row + direction[0]
                newCol = col + direction[1]
                dfs(newRow, newCol, heights[row][col], visited)
        
        # Top and bottom rows
        for col in range(colCount):
            dfs(0, col, float('-inf'), canReachPacificOcean)
            dfs(rowCount - 1, col, float('-inf'), canReachAtlanticOcean)

        # Left and right columns
        for row in range(rowCount):
            dfs(row, 0, float('-inf'), canReachPacificOcean)
            dfs(row, colCount - 1, float('-inf'), canReachAtlanticOcean)

        for cells in canReachPacificOcean:
            if cells in canReachAtlanticOcean:
                ans.append(cells)

        print(ans)
        return ans

"""
    Maintain two sets:
        canReachPacificOcean
        canReachAtlanticOcean

    Iterate through all border cells since they're guaranteed to reach one ocean
    On each cell run a dfs function that checks each adjacent direction

"""

heights1 = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
ans1 = [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
assert Solution().pacificAtlantic(heights1) == ans1, "Test failed!"

heights2 = [[1]]
ans2 = [[0,0]]
assert Solution().pacificAtlantic(heights2) == ans2, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")