import time
from typing import List, Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            return TreeNode(val, root)
        
        queue = deque()
        queue.append(root)

        while depth - 1 != 1:
            for idx in range(len(queue)):
                curr = queue.popleft()
                if (curr.left):
                    queue.append(curr.left)
                if (curr.right):
                    queue.append(curr.right)
            depth -= 1

        while queue:
            curr = queue.popleft()
            curr.left = TreeNode(val, left = curr.left)
            curr.right = TreeNode(val, right = curr.right)                

        return root
    
    """
    Use BFS to iterate through the tree until we're at depth - 1
    When we arrive at the correct depth, simply create new nodes with their children assigned correctly to the next left and right nodes, and we'll have succesfully inserted a row
    """

t0 = time.time()
assert Solution(). == , "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")