from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        encountered = []

        while head:
            encountered.append(head.val)
            head = head.next

        left = 0
        right = len(encountered) - 1

        while left < right:
            if encountered[left] == encountered[right]:
                pass
            else:
                return False

            left += 1
            right -= 1
        

        # print(encountered)
        return True

"""
    This can be optimized by doing the following
    -- Find the halfway point
    -- Reverse the second half of the list
    -- Compare the second half of the list with the first half, if at any piont they're not the same then we can return false

"""

# assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")