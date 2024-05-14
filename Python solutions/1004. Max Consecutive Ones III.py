import time
from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        encountered = [0] * 2
        left = 0
        right = 0
        ans = 0

        while right < len(nums):
            encountered[nums[right]] += 1
            right += 1

            while encountered[0] > k:
                encountered[nums[left]] -= 1
                left += 1

            ans = max(ans, right - left)
            
        # print(ans)
        return ans

nums1 = [1,1,1,0,0,0,1,1,1,1,0]
k1 = 2
ans1 = 6
nums2 = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1] 
k2 = 3
ans2 = 10
t0 = time.time()
assert Solution().longestOnes(nums1, k1) == ans1, "Test failed!"
assert Solution().longestOnes(nums2, k2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")