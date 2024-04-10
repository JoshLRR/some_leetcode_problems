import time
from typing import List

class Solution:
    # Shitty and hacky solution
    # def makeGood(self, s: str) -> str:
    #     foundChange = True
    #     sChars = list(s)
    #     n = len(sChars)

    #     while foundChange:
    #         foundChange = False

    #         for i in range(n):
    #             if i == n - 1:
    #                 break
                
    #             idx2 = i + 1
    #             while sChars[idx2] == "1" and idx2 < n - 1:
    #                 idx2 += 1

    #             if sChars[i] != "1" and ((sChars[idx2] == sChars[i].upper() and sChars[i].islower()) or (sChars[i] == sChars[idx2].upper() and sChars[idx2].islower())):
    #                 sChars[idx2] = "1"
    #                 sChars[i] = "1"
    #                 foundChange = True

    #     ans = ""
    #     for i in range(len(sChars)):
    #         if sChars[i] == "1":
    #             pass
    #         else:
    #             ans += sChars[i]

    #     print(ans)
    #     return ans
    def makeGood(self, s: str) -> str:
        stack = []

        for letter in s:
            if stack and stack[-1] == letter.lower() and letter.isupper():
                # print(stack[-1], letter)
                stack.pop()
                continue
            if stack and stack[-1] == letter.upper() and letter.islower():
                # print(stack[-1], letter)
                stack.pop()
                continue
            stack.append(letter)
            
        return "".join(stack)

s1 = "leEeetcode"
ans1 = "leetcode"
s2 = "abBAcC"
ans2 = ""
s3 = "s"
ans3 = "s"
s4 = "Pp"
ans4 = ""
s5 = "kkdsFuqUfSDKK"
ans5 = "kkdsFuqUfSDKK"
t0 = time.time()
assert Solution().makeGood(s1) == ans1, "Test failed!"
assert Solution().makeGood(s2) == ans2, "Test failed!"
assert Solution().makeGood(s3) == ans3, "Test failed!"
assert Solution().makeGood(s4) == ans4, "Test failed!"
assert Solution().makeGood(s5) == ans5, "Test failed!"
t1 = time.time()
elapsed = t1 - t0

print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")
