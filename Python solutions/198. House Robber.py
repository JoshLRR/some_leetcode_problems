from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        rob1 = 0
        rob2 = 0

        for num in nums:
            temp = max(rob1 + num, rob2)
            rob1 = rob2
            rob2 = temp
        
        return rob2

nums1 = [1,2,3,1]
ans1 = 4
assert Solution().rob(nums1) == ans1, "Test failed!"

nums2 = [2,7,9,3,1]
ans2 = 12
assert Solution().rob(nums2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")