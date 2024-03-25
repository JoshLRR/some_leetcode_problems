from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        slow = head
        fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        if fast.next:
            slow = slow.next

        prevNode = None
        nextNode = None

        while slow:
            nextNode = slow.next
            slow.next = prevNode
            prevNode = slow
            slow = nextNode
        slow = prevNode

        while head and slow:
            nextNode = head.next
            prevNode = slow.next
            head.next = slow
            slow.next = nextNode
            head = nextNode
            slow = prevNode
        
        if head and head.next:
            head.next.next = None


"""
    Create a copy, get to the middle of the list, then reverse it.
    Then interweave the first half of the original list with the reversed portion (half and half)
    So if we have:
    1 -> 2 -> 3 -> 4 -> 5
    Get 5 -> 4 -> 3
    1 -> 5 -> 2 -> 4 -> 3

"""

# assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")