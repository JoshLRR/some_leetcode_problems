from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

# # DFS Solution
# class Solution:
#     def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
#         OGtoNew = {}

#         def dfs(node: Optional['Node']) -> Optional['Node']:
#             if node in OGtoNew: return OGtoNew[node]

#             copy = Node(node.val)
#             OGtoNew[node] = copy
#             for node in node.neighbors:
#                 copy.neighbors.append(dfs(node))
                
#             return copy

#         if node:
#             return dfs(node)
#         else:
#             return None

# BFS Approach
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        OGtoNew = {node: Node(val=node.val)}
        queue = collections.deque([node])

        while queue:
            current = queue.pop()

            for neighbor in current.neighbors:
                if neighbor not in OGtoNew:
                    OGToNew[neighbor] = Node(neighbor.val)
                    queue.append(neighbor)
                OGtoNew[current].neighbors.append(OGtoNew[neighbor])
        
        return OGtoNew[node]
#

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")