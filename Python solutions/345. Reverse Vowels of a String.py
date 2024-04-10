import time

class Solution:
    def reverseVowels(self, s: str) -> str:
        vowelIndices = []
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        ans = ""
        for i, letter in enumerate(s):
            if letter in vowels:
                vowelIndices.append(letter)
        
        currVowel = 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] in vowels:
                ans += vowelIndices[currVowel]
                currVowel += 1
            else: 
                ans += s[i]

        print(ans[::-1])
        return ans[::-1]
    
"""
Can be done in a single loop with two pointers
Start one pointer at the front, one at the end
If both pointers are pointing to vowels, swap them
    Otherwise if only one is pointing to a vowel, advance the other until they're both vowels
"""
    

s1 = "hello"
ans1 = "holle"
s2 = "leetcode"
ans2 = "leotcede"
s3 = "aA"
ans3 = "Aa"
t0 = time.time()
assert Solution().reverseVowels(s1) == ans1, "Test failed!"
assert Solution().reverseVowels(s2) == ans2, "Test failed!"
assert Solution().reverseVowels(s3) == ans3, "Test failed!"
print((time.time() - t0) * 1000, "milliseconds")
# time.sleep(1)
print("\033[32mAll tests passed!\033[0m\n")