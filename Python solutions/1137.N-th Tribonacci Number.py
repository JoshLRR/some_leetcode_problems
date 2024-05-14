import time
from typing import List

class Solution:
    def tribonacci(self, n: int) -> int:
        t0, t1, t2 = 0, 1, 1

        if n == 0: return t0
        if n == 1: return t1
        if n == 2: return t2
        curr = 0
        
        for i in range(3, n + 1):
            if curr % 3 == 0:
                t0 = t0 + t1 + t2
                curr = 0
            if curr % 3 == 1:
                t1 = t0 + t1 + t2
            if curr % 3 == 2:
                t2 = t0 + t1 + t2

            curr += 1
        # print(max(t0,t1,t2))
        return max(t0,t1,t2)

'''
T0 = 0
T1 = 1
T2 = 1
T(n + 3) = T(n) + T(n+1) + T(n+2)
'''

n1 = 4
ans1 = 4
n2 = 25
ans2 = 1389537
t0 = time.time()
assert Solution().tribonacci(n1) == ans1, "Test failed!"
assert Solution().tribonacci(n2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")