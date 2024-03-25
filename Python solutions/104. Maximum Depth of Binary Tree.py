# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root: return 0

        def dfs(node: Optional[TreeNode]) -> int:
            if not node: return 0
            return max(dfs(node.left), dfs(node.right)) + 1

        return dfs(root)
        
assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")