from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        ans = [False] * len(candies)
        maxCandies = max(candies)

        for idx, kid in enumerate(candies):
            if kid + extraCandies >= maxCandies:
                ans[idx] = True

        # print(ans, candies)
        return ans
    
candies1 = [2,3,5,1,3] 
extraCandies1 = 3
ans1 = [True,True,True,False,True] 

candies2 = [4,2,1,1,2] 
extraCandies2 = 1
ans2 = [True,False,False,False,False] 

candies3 = [12,1,12] 
extraCandies3 = 10
ans3 = [True,False,True]

assert Solution().kidsWithCandies(candies1, extraCandies1) == ans1, "Test failed!"
assert Solution().kidsWithCandies(candies2, extraCandies2) == ans2, "Test failed!"
assert Solution().kidsWithCandies(candies3, extraCandies3) == ans3, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")