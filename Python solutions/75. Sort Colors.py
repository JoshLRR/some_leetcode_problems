from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        low = 0
        mid = 0
        high = len(nums) - 1

        while mid <= high:
            match nums[mid]:
                case 0:
                    nums[low], nums[mid] = nums[mid], nums[low]
                    low += 1
                    mid += 1
                case 1:
                    mid += 1
                case 2: 
                    nums[mid], nums[high], = nums[high], nums[mid]
                    high -= 1
        
        print(nums)


        
nums1 = [2,0,2,1,1,0]
ans1 = [0,0,1,1,2,2]
assert Solution().sortColors(nums1) == ans1, "Test failed!"

nums2 = [2,0,1]
ans2 = [0,1,2]
assert Solution().sortColors(nums2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")