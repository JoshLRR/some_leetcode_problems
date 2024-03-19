from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if target > nums[mid]:
                left = mid + 1
            elif target < nums[mid]:
                right = mid - 1
            else:
                return mid
        
        return -1

nums = [-1,0,3,5,9,12]
target = 9
result1 = Solution().search(nums, target)
assert result1 == 4, f"Test failed! Got {result1} instead of 4"

nums2 = [-1,0,3,5,9,12] 
target2 = 2
assert Solution().search(nums2, target2) == -1, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")