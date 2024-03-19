class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        charCount = {}
        for char in magazine:
            if char not in charCount:
                charCount[char] = 1
            else:
                charCount[char] += 1

        for char in ransomNote:
            if char not in charCount or charCount[char] == 0:
                return False
            else:
                charCount[char] -= 1

        return True

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")