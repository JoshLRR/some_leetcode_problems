import time
from typing import List

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        converted = list(s)
        stack = []
        for i, char in enumerate(converted):
            if char == '(':
                stack.append(i)
            elif char == ')':
                if stack:
                    stack.pop()
                else:
                    converted[i] = ''
        
        while stack:
            converted[stack.pop()] = ''
        # print (''.join(converted))
        return ''.join(converted)
    
    """
        1. Convert string to list since string is immutable in Python
        2. Iterate through list
        3. Keep track of indices with open paren in the stack -- push indices whenever we encounter open paren into the stack
        4. When a close paren is encountered, pop an elem from the stack. If stack is empty then replace the current index with an empty char
        5. After iterating through the string/list, replace all indices in the stack with empty strings because there are no corresponding close paren
        6. Convert list to string and return
    """
    
s1 = "lee(t(c)o)de)"
ans1 = {"lee(t(co)de)", "lee(t(c)ode)", "lee(t(c)o)de"}
s2 = "a)b(c)d"
ans2 = "ab(c)d"
s3 = "))(("
ans3 = ""
t0 = time.time()
out1 = Solution().minRemoveToMakeValid(s1)
out2 = Solution().minRemoveToMakeValid(s2)
out3 = Solution().minRemoveToMakeValid(s3)
t1 = time.time()
assert out1 in ans1, "Test failed!"
assert out2 == ans2, "Test failed!"
assert out3 == ans3, "Test failed!"
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")