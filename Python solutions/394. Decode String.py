from curses.ascii import isdigit
import time
from typing import List

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        multiplier = 0
        tempString = ""

        for char in s:
            if char == '[':
                stack.append(tempString)
                stack.append(multiplier)
                tempString = ""
                multiplier = 0
            elif char == ']':
                num = stack.pop()
                prevString = stack.pop()
                tempString = prevString + (num * tempString)
            elif char.isdigit():
                multiplier = multiplier * 10 + int(char)
            else:
                tempString += char

        return tempString

            

"""

"""
s1 = "3[a]2[bc]"
ans1 = "aaabcbc"
s2 = "3[a2[c]]"
ans2 = "accaccacc"
s3 = "2[abc]3[cd]ef"
ans3 = "abcabccdcdcdef"
t0 = time.time()
assert Solution().decodeString(s1) == ans1, "Test failed!"
assert Solution().decodeString(s2) == ans2, "Test failed!"
assert Solution().decodeString(s3) == ans3, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")