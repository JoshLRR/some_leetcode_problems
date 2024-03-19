class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        charCount = {}

        for char in s:
            if char in charCount:
                charCount[char] += 1
            else:
                charCount[char] = 1
        
        for char in t:
            if char in charCount:
                charCount[char] -= 1
                if charCount[char] == 0:
                    charCount.pop(char)
            else:   
                return False

        return len(charCount) == 0


s1 = "anagram"
t1 = "nagaram"
assert Solution().isAnagram(s1,t1) == True, "Test failed!"

s2 = "rat"
t2 = "car"
assert Solution().isAnagram(s2,t2) == False, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")