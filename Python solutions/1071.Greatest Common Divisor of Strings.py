from math import gcd

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # print(str1 + str2)
        # print(str2 + str1)
        if (str1 + str2 != str2 + str1):
            return ""

        # print(gcd(len(str1), len(str2)))
        return str1[:gcd(len(str1), len(str2))]        
        

str1 = "ABCABC"
str2 = "ABC"
ans1 = "ABC"

str3 = "ABABAB"
str4 = "ABAB"
ans2 = "AB"

str5 = "LEET"
str6 = "CODE"
ans3 = ""

assert Solution().gcdOfStrings(str1, str2) == ans1, "Test failed!"
assert Solution().gcdOfStrings(str3, str4) == ans2, "Test failed!"
assert Solution().gcdOfStrings(str5, str6) == ans3, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")