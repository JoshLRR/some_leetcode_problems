import time
from typing import List

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        prefix = ""

        for idx, letter in enumerate(word):
            prefix += letter
            if letter == ch:
                prefix = prefix[::-1]

                # print(prefix + word[idx + 1::])

                return prefix + word[idx + 1::]
        
        # print("Returning word")
        return word
# class Solution:
#     def reversePrefix(self, word: str, ch: str) -> str:
#         idx=word.find(ch)    
#         if idx:
#             return word[:idx+1][::-1]+ word[idx+1:]
#         return word

word1 = "abcdefd"
ch1 = "d"
ans1 = "dcbaefd"
word2 = "xyxzxe"
ch2 = "z"
ans2 = "zxyxxe"
word3 = "abcd"
ch3 = "z"
ans3 = "abcd"
t0 = time.time()
assert Solution().reversePrefix(word1, ch1) == ans1, "Test failed!"
assert Solution().reversePrefix(word2, ch2) == ans2, "Test failed!"
assert Solution().reversePrefix(word3, ch3) == ans3, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")