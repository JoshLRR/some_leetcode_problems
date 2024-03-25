from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        m = len(matrix[0])

        right = m
        bot = n
        left = 0
        top = 0
        ans = []

        while(left < right and bot > top):
            for i in range(left, right):
                ans.append(matrix[top][i])
            top += 1

            for i in range(top, bot):
                ans.append(matrix[i][right - 1])
            right -= 1

            if not (left < right and top < bot): break

            for i in range(right - 1, left - 1, -1):
                ans.append(matrix[bot - 1][i])
            bot -= 1

            for i in range(bot - 1, top - 1, -1):
                ans.append(matrix[i][left])
            left += 1


        print(ans)
        return ans

"""
    Go right -> Change right-side boundary
    Go down -> Change bottom boundary
    Go left -> change left-side boundary
    Go up -> change top side boundary
"""


matrix1 = [[1,2,3],[4,5,6],[7,8,9]]
ans1 = [1,2,3,6,9,8,7,4,5]
assert Solution().spiralOrder(matrix1) == ans1, "Test failed!"

matrix2 = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
ans2 = [1,2,3,4,8,12,11,10,9,5,6,7]
assert Solution().spiralOrder(matrix2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")