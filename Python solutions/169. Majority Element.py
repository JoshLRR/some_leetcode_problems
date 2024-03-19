from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = 0
        count = 0

        for num in nums:
            if num != candidate and count > 0:
                count -= 1
            elif num != candidate and count == 0:
                candidate = num
                count = 1
            elif num == candidate:
                count += 1

        return candidate

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")