from typing import List

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        sums = 0
        sumMap = {}
        sumMap[0] = 1

        for i in range(len(nums)):
            sums += nums[i]
            count += sumMap[sums - k]
            sumMap[sums] = sumMap(sums) + 1

        return count

nums1 = [1,1,1]
k1 = 2
ans1 = 2
assert Solution().subarraySum(nums1, k1) == ans1,"Test failed!"

nums2 = [1,2,3]
k2 = 3
ans2 = 2
assert Solution().subarraySum(nums2, k2) == ans2,"Test failed!"

print("\033[32mAll tests passed!\033[0m\n")