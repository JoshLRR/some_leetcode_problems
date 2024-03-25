from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        encountered = set()

        for num in nums:
            if num in encountered:
                return True
            else:
                encountered.add(num)

        return False

nums1 = [1,2,3,1]
assert Solution().containsDuplicate(nums1) == True, "Test failed!"

nums2 = [1,2,3,4]
assert Solution().containsDuplicate(nums2) == False, "Test failed!"

nums3 = [1,1,1,3,3,4,3,2,4,2]
assert Solution().containsDuplicate(nums3) == True, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")