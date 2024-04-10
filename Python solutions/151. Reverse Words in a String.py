import time
from typing import List

class Solution:
    # def reverseWords(self, s: str) -> str:
    #     s = s.strip()
    #     ans = ""
    #     temp = ""
    #     for i in range(len(s) - 1, -1, -1):
    #         if s[i] != ' ':
    #             temp += s[i]
    #         else:
    #             if temp != "":
    #                 ans += temp[::-1] 
    #                 ans += " "
    #                 temp = ""
    #     ans += temp[::-1]

    #     print(ans)
    #     return ans

    def reverseWords(self, s: str) -> str:
        temp = s.split()
        temp.reverse()
        output = " ".join(temp)
        return output

s1 = "the sky is blue"
ans1 = "blue is sky the"
s2 = "  hello world  "
ans2 = "world hello"

t0 = time.time_ns()
assert Solution().reverseWords(s1) == ans1, "Test failed!"
assert Solution().reverseWords(s2) == ans2, "Test failed!"
print((time.time_ns() - t0) / 1e6)

print("\033[32mAll tests passed!\033[0m\n")