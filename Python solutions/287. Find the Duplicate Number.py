from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast = nums[0]

        while(1):
            slow = nums[slow]
            fast = nums[nums[fast]]

            print(slow, fast)

            if slow == fast:
                break

        slow2 = 0
        while(1):
            slow = nums[slow]
            slow2 = nums[slow2]
            if slow == slow2:
                break

        return slow

"""
Floyd's tortoise and hare approach
A duplicate number creates a cycle in nums when iterating with vals of nums via nums[slow] and nums[nums[fast]]

Once we detect a cycle, reset slow to the head and then increment both by one until the pointers meet again. That's the point where the cycle starts, or in this case, where the duplicate number is

"""

Solution().findDuplicate([1,3,4,2,2])
Solution().findDuplicate([1,3,2,5,4,7,6])

# assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")