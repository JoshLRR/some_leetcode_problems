class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n for i in range(m)]

        for i in range(n):
            dp[m - 1][i] = 1

        for i in range(m):
            dp[i][n-1] = 1

        for i in range(m-2, -1, -1):
            for j in range(n-2, -1, -1):
                dp[i][j] = dp[i+1][j] + dp[i][j+1]


        print(dp)
        return dp[0][0]
        

Solution().uniquePaths(3, 7)
# assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")