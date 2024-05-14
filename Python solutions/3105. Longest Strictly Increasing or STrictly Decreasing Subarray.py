import time
from typing import List

class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:


nums1 = [1,4,3,3,2]
ans1 = 2
nums2 = [3,3,3,3]
ans2 = 1
nums3 = [3,2,1]
ans3 = 3
nums4 = [1]
ans4 = 1
nums5 = [1,5,2]
ans5 = 2
t0 = time.time()
assert Solution().longestMonotonicSubarray(nums1) == ans1, "Test failed!"
assert Solution().longestMonotonicSubarray(nums2) == ans2, "Test failed!"
assert Solution().longestMonotonicSubarray(nums3) == ans3, "Test failed!"
assert Solution().longestMonotonicSubarray(nums4) == ans4, "Test failed!"
assert Solution().longestMonotonicSubarray(nums5) == ans5, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")