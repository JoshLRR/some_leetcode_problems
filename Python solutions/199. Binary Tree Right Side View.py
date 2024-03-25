from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        queue = deque()
        queue.append(root)

        while queue:
            n = len(queue)
            for i in range(len(queue)):
                curr = queue[0]
                queue.popleft()

                if i == n - 1:
                    ans.append(curr.val)
                
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)


        return ans



assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")