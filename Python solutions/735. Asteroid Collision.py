import time
from typing import List

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for asteroid in asteroids:
            while stack and asteroid < 0 and stack[-1] > 0:
                if stack[-1] == -asteroid:
                    stack.pop()
                    break
                elif stack[-1] < -asteroid:
                    stack.pop()
                    continue
                elif stack[-1] > -asteroid:
                    break
            else:
                stack.append(asteroid)

            # if asteroid < 0 and stack:
            #     if asteroid < 0 and stack[-1] < 0:
            #         stack.append(asteroid)
            #         # continue
            #     elif abs(asteroid) == stack[-1]:
            #         # print(asteroid, stack)
            #         stack.pop()
            #     elif abs(asteroid) > stack[-1]:
            #         stack.pop()
            #         # stack.append(asteroid)
            #     # else:
            #     #     continue
            # else:
            #     # print(asteroid, stack)
            #     stack.append(asteroid)

        print(stack)
        return stack       


asteroids1 = [5,10,-5]
ans1 = [5,10]
asteroids2 = [8,-8]
ans2 = []
asteroids3 = [10,2,-5]
ans3 = [10]
asteroids4 = [-2,-1,1,2]
ans4 = [-2,-1,1,2]
asteroids5 = [-2,-2,1,-2]
ans5 = [-2,-2,-2]
t0 = time.time()
assert Solution().asteroidCollision(asteroids1) == ans1, "Test failed!"
assert Solution().asteroidCollision(asteroids2) == ans2, "Test failed!"
assert Solution().asteroidCollision(asteroids3) == ans3, "Test failed!"
assert Solution().asteroidCollision(asteroids4) == ans4, "Test failed!"
assert Solution().asteroidCollision(asteroids5) == ans5, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")