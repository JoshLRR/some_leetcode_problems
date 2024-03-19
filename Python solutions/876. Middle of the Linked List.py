from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head

        while (fast.next.next and fast.next):
            slow = slow.next
            fast = fast.next.next

        return slow

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")