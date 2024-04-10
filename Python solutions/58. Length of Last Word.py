class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # words = s.split()
        # while words[-1] == '':
        #     words.pop()
        #     # print(words)

        # return len(words[-1])
        return len(s.split()[-1])
    # def lengthOfLastWord(self, s):
    
    #     wordlist = s.split()
    #     print(wordlist)
    #     if wordlist:
    #         return len(wordlist[-1])
    #     return 0

    

s1 = "Hello World"
ans1 = 5
assert Solution().lengthOfLastWord(s1) == ans1, "Test failed!"

s2 = "   fly me   to   the moon  "
ans2 = 4
assert Solution().lengthOfLastWord(s2) == ans2, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")