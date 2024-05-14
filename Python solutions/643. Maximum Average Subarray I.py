import time
from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        left = 0
        right = k - 1
        ans = float('-inf')
        currSum = sum(nums[left:right+1])


        while right < len(nums):
            currAvg = currSum / k
            ans = max(ans, currAvg)
            currSum -= nums[left]
            left += 1
            right += 1
            if (right < len(nums)):
                currSum += nums[right]
            
        return ans

nums1 = [1,12,-5,-6,50,3]
k1 = 4
ans1 = 12.75000
nums2 = [5]
k2 = 1
ans2 = 5.00000
t0 = time.time()
assert Solution().findMaxAverage(nums1,k1) == ans1, "Test failed!"
assert Solution().findMaxAverage(nums2,k2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")