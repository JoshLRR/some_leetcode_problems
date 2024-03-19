from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if root is None: return True

        def measureHeight(node: Optional[TreeNode]) -> int:
            if node is None: return 0

            left = measureHeight(node.left)
            right = measureHeight(node.right)

            if left == -1 or right == -1 or abs(right - left) > 1:
                return -1
            
            return max(left, right) + 1

        if measureHeight(root) == -1: return False

        return True


 


assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")