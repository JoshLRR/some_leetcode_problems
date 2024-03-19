from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root: return False

        def dfs(node: Optional[TreeNode], leftBoundary: int, rightBoundary: int) -> bool:
            if not node: return True
            if node.val <= leftBoundary or node.val >= rightBoundary:
                return False
            
            return dfs(node.left, leftBoundary, node.val) and dfs(node.right, node.val, rightBoundary)

        return dfs(root, -1e12, 1e12)

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")