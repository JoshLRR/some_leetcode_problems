from typing import Optional
from typing import List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: return []

        queue = deque()
        queue.append(root)
        ans = []

        while (queue):
            currRow = []
            rowSize = len(queue)
            for i in range(rowSize):
                temp = queue.popleft()

                if temp.left: 
                    queue.append(temp.left)
                if temp.right: 
                    queue.append(temp.right)

                currRow.append(temp.val)
            ans.append(currRow)

        # print(ans)
        return ans



# Utility function to construct a binary tree from a list.
def constructTree(nodeList):
    if not nodeList:
        return None
    root = TreeNode(nodeList[0])
    queue = [root]
    i = 1
    while queue and i < len(nodeList):
        current = queue.pop(0)
        if nodeList[i] is not None:
            current.left = TreeNode(nodeList[i])
            queue.append(current.left)
        i += 1
        if i < len(nodeList) and nodeList[i] is not None:
            current.right = TreeNode(nodeList[i])
            queue.append(current.right)
        i += 1
    return root

# Tests
tests = [
    ([3,9,20,None,None,15,7], [[3],[9,20],[15,7]]),
    ([1], [[1]]),
    ([], [])
]

for test in tests:
    treeInput, expectedOutput = test
    root = constructTree(treeInput)
    assert Solution().levelOrder(root) == expectedOutput, f"Test failed for input: {treeInput}"

print("\033[32mAll tests passed!\033[0m\n")
