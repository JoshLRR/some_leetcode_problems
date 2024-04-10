from typing import List
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = float('inf')
        n = len(nums)
        for i in range(len(nums)):
            curr = 0
            for j in range(i, n):
                curr |= nums[j]
                if curr >= k:
                    ans = min(ans, j - i + 1)
                    break
        
        return ans if ans != float('inf') else -1


assert Solution().minimumSubarrayLength([1,2,3], 2) == 1, "Test failed!"
assert Solution().minimumSubarrayLength([2,1,8], 10) == 3, "Test failed!"
assert Solution().minimumSubarrayLength([1,2], 0) == 1, "Test failed!"
assert Solution().minimumSubarrayLength([16,1,2,20,32], 45) == 2, "Test failed!"


# Solution().minimumSubarrayLength([1,2,3], 2)

print("\033[32mAll tests passed!\033[0m\n")