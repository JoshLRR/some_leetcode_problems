import time
from typing import List

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        encountered = {}
        for idx, letter in enumerate(s):
            if letter not in encountered:
                if t[idx] in encountered.values():
                    return False
                encountered[letter] = t[idx]
                # print(encountered)
            else:
                if t[idx] != encountered[letter]:
                    # print("Returning False", letter, encountered[letter], encountered)
                    return False

        return True
    
s1 = "egg"
t1 = "add"

s2 = "foo"
t2 = "bar"

s3 = "paper"
t3 = "title"

s4 = "badc"
t4 = "baba"

t0 = time.time()
assert Solution().isIsomorphic(s1, t1) == True, "Test failed!"
assert Solution().isIsomorphic(s2, t2) == False, "Test failed!"
assert Solution().isIsomorphic(s3, t3) == True, "Test failed!"
assert Solution().isIsomorphic(s4, t4) == False, "Test failed!"
print((time.time() - t0) * 1000, "milliseconds")

print("\033[32mAll tests passed!\033[0m\n")