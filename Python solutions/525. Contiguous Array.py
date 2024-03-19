from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        runningSum = 0
        countMap = {0: -1}
        maxSubarray = 0
         
        for i, num in enumerate(nums):
            if num == 1:
                runningSum += 1
            else:
                runningSum -= 1

            if runningSum in countMap:
                maxSubarray = max(maxSubarray, i - countMap[runningSum])
            else:
                countMap[runningSum] = i
            # print(countMap, maxSubarray, sep = "----")

        return maxSubarray
        


nums1 = [0,1]
ans1 = 2
assert Solution().findMaxLength(nums1) == ans1, "Test failed!"

nums2 = [0,1,0]
ans2 = 2
assert Solution().findMaxLength(nums2) == ans2, "Test failed!"

nums3 = [1,1,0,0,1,1,0,1,1]
ans3 = 6
assert Solution().findMaxLength(nums3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")