from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxDiameter = 0

        def dfs(node: Optional[TreeNode]) -> int:
            if node is None: return 0
            nonlocal maxDiameter

            leftHeight = dfs(node.left)
            rightHeight = dfs(node.right)

            maxDiameter = max(leftHeight + rightHeight, maxDiameter)
            
            return 1 + max(leftHeight, rightHeight)
        
        dfs(root)
        return maxDiameter

# Helper function to build a tree from a list
def build_tree(values):
    if not values:
        return None
    root = TreeNode(values[0])
    queue = [root]
    front = 0
    index = 1
    while index < len(values):
        node = queue[front]
        front += 1
        if values[index] is not None:
            node.left = TreeNode(values[index])
            queue.append(node.left)
        index += 1
        if index < len(values) and values[index] is not None:
            node.right = TreeNode(values[index])
            queue.append(node.right)
        index += 1
    return root

# Tests
root1 = build_tree([1,2,3,4,5])
assert Solution().diameterOfBinaryTree(root1) == 3, "Test 1 failed!"

root2 = build_tree([1,2])
assert Solution().diameterOfBinaryTree(root2) == 1, "Test 2 failed!"

print("\033[32mAll tests passed!\033[0m\n")