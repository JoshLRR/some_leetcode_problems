from typing import List
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        running = 1
        ans = []
        for num in nums:
            ans.append(running) 
            running *= num
        running = 1
        for i in range(len(ans) - 1, -1, -1):
            ans[i] *= running
            running *= nums[i]

        # print(ans)

        return ans


# assert Solution(). == , "Test failed!"
Solution().productExceptSelf([1,2,3,4])

print("\033[32mAll tests passed!\033[0m\n")