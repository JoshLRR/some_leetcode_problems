from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2:
            return None

        preHead = ListNode(0)
        dummy = preHead

        while list1 and list2:
            if list1.val < list2.val:
                dummy.next = list1
                list1 = list1.next
                dummy = dummy.next
            else:
                dummy.next = list2
                list2 = list2.next
                dummy = dummy.next

        while list1:
            dummy.next = list1
            list1 = list1.next
            dummy = dummy.next

        while list2:
            dummy.next = list2
            list2 = list2.next
            dummy = dummy.next


        return preHead.next


# Helper function to convert list to ListNode
def toListNode(lst):
    head = ListNode(0)
    current = head
    for val in lst:
        current.next = ListNode(val)
        current = current.next
    return head.next

# Helper function to convert ListNode to list (for easier assertion)
def toList(node):
    lst = []
    while node:
        lst.append(node.val)
        print(f"{node.val}", end = " ")
        node = node.next
    print()
    return lst

# Test cases
tests = [
    ([1, 2, 4], [1, 3, 4], [1, 1, 2, 3, 4, 4]),
    ([], [], []),
    ([], [0], [0]),
    ([1, 2, 3], [4, 5, 6], [1, 2, 3, 4, 5, 6]),
    ([1], [2, 3, 4, 5], [1, 2, 3, 4, 5])
]

for i, (list1, list2, expected) in enumerate(tests):
    result = Solution().mergeTwoLists(toListNode(list1), toListNode(list2))
    assert toList(result) == expected, f"Test {i + 1} failed!"

print("\033[32mAll tests passed!\033[0m\n")
