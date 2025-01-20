import time
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    runningSum = 0
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def dfs(node: TreeNode) -> TreeNode:
            if node.right is not None:
                dfs(node.right)

            self.runningSum += node.val
            node.val = self.runningSum

            if node.left is not None:
                dfs(node.left)
                
            return node
        
        return dfs(root)


t0 = time.time()
assert Solution(). == , "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")