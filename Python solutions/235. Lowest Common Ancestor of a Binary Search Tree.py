# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        large = max(p.val, q.val)
        small = min(p.val, q.val)

        while root is not None:
            if root.val < small:    # pq on the right
                root = root.right
            if root.val > large:    # pq on the left
                root = root.left
            if root.val >= small and root.val <= large:   # root in between p and q
                return root

        return None 

# Helper function to insert nodes into the BST
def insert_into_bst(root, val):
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_into_bst(root.left, val)
    else:
        root.right = insert_into_bst(root.right, val)
    return root

# Test 1: Simple BST
root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)

p = root.left  # Node with value 1
q = root.right  # Node with value 3

# The LCA of 1 and 3 in this BST is 2.
assert Solution().lowestCommonAncestor(root, p, q) == root, "Test 1 failed!"

# Test 2: More complex BST
root = TreeNode(6)
values_for_bst = [2, 8, 0, 4, 7, 9, 3, 5]
for val in values_for_bst:
    root = insert_into_bst(root, val)

p = root.left.right.right  # Node with value 5
q = root.left  # Node with value 2

# The LCA of 2 and 5 in this BST is 2.
assert Solution().lowestCommonAncestor(root, p, q) == root.left, "Test 2 failed!"

print("\033[32mAll tests passed!\033[0m\n")