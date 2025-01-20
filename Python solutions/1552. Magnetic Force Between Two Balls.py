import time
from typing import List

class Solution:

    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        n = len(position)
        left = 0
        right = position[n - 1]
        requiredForce = 0

        def canPut(position: List[int], m: int, max: int) -> bool:
            count = 1
            last = position[0]

            for idx in range(1, n):
                if (position[idx] - last >= max):
                    last = position[idx]
                    count += 1

            return count >= m
        
        while left <= right:
            mid = left + (right - left) // 2
            if canPut(position, m, mid):
                requiredForce = mid
                left = mid + 1
            else:
                right = mid - 1
        

        return requiredForce



position1 = [1,2,3,4,7]
m1 = 3
ans1 = 3

position2 = [5,4,3,2,1,1000000000]
m2 = 2
ans2 = 999999999

test1 = Solution().maxDistance(position1, m1)
test2 = Solution().maxDistance(position2, m2)

t0 = time.time()
assert test1 == ans1, "Test failed! Got " + str(test1) + " instead of " + str(ans1)
assert test2 == ans2, "Test failed! Got " + str(test2) + " instead of " + str(ans2)
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")