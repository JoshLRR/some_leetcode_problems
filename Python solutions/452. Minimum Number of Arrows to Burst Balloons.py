from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        currBalloon = points[0]
        numBalloons = len(points)
        arrows = 1
        idx = 1

        while idx < numBalloons:
            if currBalloon[1] >= points[idx][0]:
                idx += 1
            else:
                arrows += 1
                currBalloon = points[idx]
                idx += 1

        # print(arrows)
        return arrows

points1 = [[10,16],[2,8],[1,6],[7,12]]
ans1 = 2
assert Solution().findMinArrowShots(points1) == ans1, "Test failed!"

points2 = [[1,2],[3,4],[5,6],[7,8]]
ans2 = 4
assert Solution().findMinArrowShots(points2) == ans2, "Test failed!"

points3 = [[1,2],[2,3],[3,4],[4,5]]
ans3 = 2
assert Solution().findMinArrowShots(points3) == ans3, "Test failed!"

points4 = [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
ans4 = 2
assert Solution().findMinArrowShots(points4) == ans4, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")