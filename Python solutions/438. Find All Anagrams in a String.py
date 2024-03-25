from typing import List
from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        targetDict = Counter(p)
        ans = []

        left = 0
        right = len(p) - 1

        while right < len(s):
            if s[left] in targetDict:
                windowDict = Counter(s[left : left + len(p)])
                # print(windowDict)
                if windowDict == targetDict:
                    ans.append(left)
            
            left += 1
            right += 1

        # print(ans)
        return ans

"""
    Can and should be optimized by not unecessarily recounting chars that remain in the window
    Focus on the chars moving out and moving into the window and adjust the map accordingly
        This will prevent unnecessary recounting on every iteration
"""
        
s1 = "cbaebabacd"
p1 = "abc"
ans1 = [0,6]
assert Solution().findAnagrams(s1,p1) == ans1, "Test failed!"

s2 = "abab"
p2 = "ab"
ans2 = [0,1,2]
assert Solution().findAnagrams(s2,p2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")