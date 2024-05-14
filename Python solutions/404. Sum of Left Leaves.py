import time
from typing import List
from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:

        def dfs(node: Optional[TreeNode], isLeft) -> int: 
            if not node: return 0

            if not node.left and not node.right and isLeft:
                return node.val

            return dfs(node.left, True) + dfs(node.right, False)

        return dfs(root, False)


tree1 = TreeNode(3, TreeNode(9), TreeNode(20, TreeNode(15), TreeNode(7)))
ans1 = 24
tree2 = TreeNode(1)
ans2 = 0
t0 = time.time()
assert Solution().sumOfLeftLeaves(tree1) == ans1, "Test failed!"
assert Solution().sumOfLeftLeaves(tree2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")