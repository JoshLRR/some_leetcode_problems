class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        encountered = {}
        left = 0
        longest = 0

        for right in range(len(s)):
            if s[right] in encountered.keys():
                left = max(left, encountered[s[right]] + 1)
            encountered[s[right]] = right
            longest = max(longest, right - left + 1)

        # print(longest)
        return longest

s1 = "abcabcbb"
ans1 = 3
assert Solution().lengthOfLongestSubstring(s1) == ans1, "Test failed!"

s2 = "bbbbb"
ans2 = 1
assert Solution().lengthOfLongestSubstring(s2) == ans2, "Test failed!"

s3 = "pwwkew"
ans3 = 3
assert Solution().lengthOfLongestSubstring(s3) == ans3, "Test failed!"

s4 = "au"
ans4 = 2
assert Solution().lengthOfLongestSubstring(s4) == ans4, "Test failed!"

s5 = "aab"
ans5 = 2
assert Solution().lengthOfLongestSubstring(s5) == ans5, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")