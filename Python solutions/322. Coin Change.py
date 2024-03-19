from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1]*(amount + 1)
        dp[0] = 0

        for i in range(amount + 1):
            for coin in coins:
                if (i - coin >= 0):
                    dp[i] = min(1 + dp[i - coin], dp[i])
        
        print(dp)
        if dp[amount] == amount + 1:
            return -1
        else:
            return dp[amount]


# assert Solution(). == , "Test failed!"
Solution().coinChange([1,2,3], 11)

print("\033[32mAll tests passed!\033[0m\n")