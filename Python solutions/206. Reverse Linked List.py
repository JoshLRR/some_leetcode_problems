from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None: return None
        prev = None
        curr = head
        next = None

        while head:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        head = prev

        return head

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")