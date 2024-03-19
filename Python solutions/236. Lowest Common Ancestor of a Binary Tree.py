# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def findLCA(node: 'TreeNode') -> 'TreeNode':
            if node is None or node is p or node is q:
                return node
            
            leftNode = findLCA(node.left)
            rightNode = findLCA(node.right)

            if leftNode and rightNode:
                return node
            elif leftNode: 
                return leftNode
            elif rightNode:
                return rightNode
            
            return None
        
        return findLCA(root)

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")