from typing import List
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        closest = 1e9
        ans = []
        min_heap = []
        for point in points:
            distance = (point[0] * point[0]) + (point[1] * point[1])
            heapq.heappush(min_heap, (distance, point))

        for i in range(k):
            ans.append(heapq.heappop(min_heap)[1])

        print(ans)
        return ans

points1 = [[1,3], [-2,2]]
k1 = 1
ans1 = [[-2,2]]
assert Solution().kClosest(points1, k1) == ans1, "Test failed!"

points2 = [[3,3],[5,-1],[-2,4]]
k2 = 2
ans2 = [[3,3],[-2,4]] # or [[-2,4],[3,3]]
assert Solution().kClosest(points2, k2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")