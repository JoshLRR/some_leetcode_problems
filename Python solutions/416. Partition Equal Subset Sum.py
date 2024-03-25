from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        totalSum = sum(nums)
        target = totalSum / 2
        if totalSum % 2 == 1:   
            return False        
        dp = set()
        dp.add(0)
        for i in range(len(nums) - 1, -1, -1):
            nextDP = set()
            for num in dp:
                nextDP.add(nums[i] + num)
                nextDP.add(num)
            dp = nextDP
            
            if target in dp:
                return True
        
    
        return False


nums1 = [1,5,11,5]
assert Solution().canPartition(nums1) == True, "Test failed!"

nums2 = [1,2,3,5]
assert Solution().canPartition(nums2) == False, "Test failed!"

nums3 = [2,2,1,1]
assert Solution().canPartition(nums3) == True, "Test Failed!"

print("\033[32mAll tests passed!\033[0m\n")