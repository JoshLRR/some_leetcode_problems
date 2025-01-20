import time
from typing import List

class Solution:
    def reverseParentheses(self, s: str) -> str:
        ans = ['']

        for letter in s:
            if letter == '(':
                ans.append('')
            elif letter == ')':
                ans[len(ans) - 2] += ans.pop()[::-1]
            else:
                ans[-1] += letter

        return "".join(ans)


s1 = "(abcd)"
ans1 = "dcba"

s2 = "(u(love)i)"
ans2 = "iloveu"

s3 = "(ed(et(oc))el)"
ans3 = "leetcode"

t0 = time.time()
test1 = Solution().reverseParentheses(s1)
test2 = Solution().reverseParentheses(s2)
test3 = Solution().reverseParentheses(s3)
t1 = time.time()
assert test1 == ans1, "Test failed!"
assert test2 == ans2, "Test failed!"
assert test3 == ans3, "Test failed!"
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")