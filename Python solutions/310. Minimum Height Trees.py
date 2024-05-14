import time
from typing import List
from collections import defaultdict
from collections import deque

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        
        adjList = defaultdict(list)
        degree = [0] * n
        for edge in edges:
            adjList[edge[0]].append(edge[1])
            adjList[edge[1]].append(edge[0])
            degree[edge[0]] += 1
            degree[edge[1]] += 1

        leaves = deque([i for i in range(n) if degree[i] == 1])

        remaining_nodes = n
        while remaining_nodes > 2:
            leaves_count = len(leaves)
            remaining_nodes -= leaves_count
            for _ in range(leaves_count):
                leaf = leaves.popleft()
                for neighbor in adjList[leaf]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        leaves.append(neighbor)

        return list(leaves)


n1 = 4
edges1 = [[1,0],[1,2],[1,3]]
ans1 = [1]
n2 = 6
edges2 = [[3,0],[3,1],[3,2],[3,4],[5,4]]
ans2 = [3,4]
t0 = time.time()
# assert Solution().findMinHeightTrees(n1,edges1) == ans1, "Test failed!"
assert Solution().findMinHeightTrees(n2,edges2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")