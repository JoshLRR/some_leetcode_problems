import time
from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        for num in nums:
            k ^= num
        print(bin(k))

        while k:
            ans += k & 1
            k >>= 1

        # print(ans)
        return ans


nums1 = [2,1,3,4]
k1 = 1
ans1 = 2
nums2 = [2,0,2,0]
k2 = 0
ans2 = 0
t0 = time.time()
assert Solution().minOperations(nums1, k1) == ans1, "Test failed!"
assert Solution().minOperations(nums2, k2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")