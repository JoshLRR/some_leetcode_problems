class Solution:
    def longestPalindrome(self, s: str) -> int:
        letterCount = {}
        odds = 0

        for char in s:
            if char in letterCount:
                letterCount[char] += 1
            else:
                letterCount[char] = 1
            
            if letterCount[char] % 2 == 0:
                odds -= 1
            else:
                odds += 1
        
        if odds > 1:
            return len(s) - odds + 1
        
        return len(s)


assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")