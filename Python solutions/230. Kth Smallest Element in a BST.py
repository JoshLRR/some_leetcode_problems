from typing import Optional
import heapq
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.minHeap = []

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if not root:
            return -1

        def addToHeap(node: Optional[TreeNode]) -> None:
            if node is None: return

            heapq.heappush(self.minHeap, node.val)
            addToHeap(node.left)
            addToHeap(node.right)
        
        addToHeap(root)

        for i in range(k-1):
            heapq.heappop(self.minHeap)

        return self.minHeap[0]

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")