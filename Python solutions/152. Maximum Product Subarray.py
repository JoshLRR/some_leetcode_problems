from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxHere = nums[0]
        maxSoFar = nums[0]
        minSoFar = nums[0]

        for i in range(1, len(nums)):
            if nums[i] < 0:
                maxHere, minSoFar = minSoFar, maxHere

            maxHere *= nums[i]
            maxHere = max(nums[i], maxHere)

            minSoFar *= nums[i]
            minSoFar = min(nums[i], minSoFar)
            
            maxSoFar = max(maxSoFar, maxHere)

        print(maxSoFar)
        return maxSoFar


nums1 = [2,3,-2,4]
ans1 = 6
assert Solution().maxProduct(nums1) == ans1, "Test failed!"

nums2 = [-2,0,-1]
ans2 = 0
assert Solution().maxProduct(nums2) == ans2, "Test failed!"

nums3 = [2,-5,-2,-4,3]
ans3 = 24
assert Solution().maxProduct(nums3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")