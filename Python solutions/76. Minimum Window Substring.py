from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        left = 0
        minLeft = 0
        right = 0
        minLength = float('inf')

        targetMap = Counter(t)
        windowMap = {}
        relevantChars = 0

        while right < len(s):
            rightChar = s[right]

            if rightChar in targetMap:
                if rightChar in windowMap:
                    windowMap[rightChar] += 1
                else:
                    windowMap[rightChar] = 1

                if (windowMap[rightChar] <= targetMap[rightChar]):
                    relevantChars += 1
            right += 1

            while relevantChars == len(t):
                if right - left < minLength:
                    minLength = right - left
                    minLeft = left

                leftChar = s[left]
                if leftChar in targetMap:
                    windowMap[leftChar] -= 1

                    if (windowMap[leftChar] < targetMap[leftChar]):
                        relevantChars -= 1
                left += 1

        if minLength == float('inf'):
            return ""
        else:
            # print(s[minLeft : minLeft + minLength])
            return s[minLeft : minLeft + minLength]
        
            

        
"""
    Sliding Window 

    Expand sliding window until all characters in t are found in s
        Keep track of relevant indices and count relevant characters

    Once all characters are found in the window, start shrinking the window
        If window is succesfully shrunk without affecting relevant character count, update relevant indices to keep track of the minimum length string
    

"""

s1 = "ADOBECODEBANC" 
t1 = "ABC"
ans1 = "BANC"
assert Solution().minWindow(s1, t1) == ans1, "Test failed!"

s2 = "a"
t2 = "a"
ans2 = "a"
assert Solution().minWindow(s2, t2) == ans2, "Test failed!"

s3 = "a"
t3 = "aa"
ans3 = ""
assert Solution().minWindow(s3, t3) == ans3, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")