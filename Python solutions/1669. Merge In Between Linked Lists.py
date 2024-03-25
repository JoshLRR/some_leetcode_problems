# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        preHead = ListNode()
        dummy = list1
        preHead.next = dummy

        for i in range(a - 1):
            dummy = dummy.next
            list1 = list1.next

        for i in range(a - 1, b + 1):
            list1 = list1.next

        dummy.next = list2
        while list2:
            dummy = dummy.next
            list2 = list2.next

        dummy.next = list1
        
        return preHead.next
            

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")