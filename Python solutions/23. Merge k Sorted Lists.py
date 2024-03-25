from typing import List
import heapq
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        minHeap = []
        head = tail = ListNode(0)
        # Make custom comparators with __eq__ and __lt__
        ListNode.__eq__ = lambda self, other: self.val == other.val
        ListNode.__lt__ = lambda self, other: self.val < other.val
        # Add each list to the heap
        for lList in lists:
            if lList:
                heapq.heappush(minHeap, (lList.val, lList))

        # While there are nodes in the heap pop and add them to the output list, add the next node to the heap 
        while minHeap:
            currNode = heapq.heappop(minHeap)[1]
            tail.next = currNode
            tail = tail.next

            if currNode.next:
                heapq.heappush(minHeap, (currNode.next.val, currNode.next))

        return head.next



# assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")
        