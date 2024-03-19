class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxProfit = 0
        minPurchasePrice = float('inf')

        for price in prices:
            if price < minPurchasePrice:
                minPurchasePrice = price
            
            dayProfit = price - minPurchasePrice
            if dayProfit > maxProfit:
                maxProfit = dayProfit

        print(maxProfit)
        return maxProfit

# Iterate through prices

prices1 = [7,1,5,3,6,4]
ans1 = 5
assert Solution().maxProfit(prices1) == ans1, "Test failed!"

prices2 = [7,6,4,3,1]
ans2 = 0
assert Solution().maxProfit(prices2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")