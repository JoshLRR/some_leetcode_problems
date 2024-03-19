# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 0
        right = n - 1

        while (left <= right):
            mid = left + (right - left) // 2
            if not isBadVersion(mid): 
                left = mid + 1
            else:
                right = mid - 1
        
        return left


# Modified binary search
# if mid is false, right is true --> look right
# if left is false, mid is true --> look left
# if mid-1 false, mid true, mid+1 true --> mid == target

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")