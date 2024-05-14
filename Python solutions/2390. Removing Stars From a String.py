import time
from typing import List

class Solution:
    def removeStars(self, s: str) -> str:
        stack = []

        for char in s:
            if char == "*":
                stack.pop()
            else:
                stack.append(char)
            
        return "".join(stack)


s1 = "leet**cod*e"
ans1 = "lecoe"
s2 = "erase*****"
ans2 = ""
t0 = time.time()
assert Solution().removeStars(s1) == ans1, "Test failed!"
assert Solution().removeStars(s2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")