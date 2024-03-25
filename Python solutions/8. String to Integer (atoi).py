class Solution:
    def myAtoi(self, s: str) -> int:
        
        return 0


"""
    1. Ignore leading white space
    2. Check for - or +
    3. Read chars until a non-digit, ignore everything including and after
    4. "123" -> 123, "0032" --> 32
    5. If int is out of 32 bit range (-2e31, 2e31 - 1) then clamp it so it remains in range
    6. Return the int as final result
"""

s1 = "42"
ans1 = 42
assert Solution().myAtoi(s1) == ans1, "Test failed!"

s2 = "   -42"
ans2 = -42
assert Solution().myAtoi(s2) == ans2, "Test failed!"

s3 = "4193 with words"
ans3 = 4193
assert Solution().myAtoi(s3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")