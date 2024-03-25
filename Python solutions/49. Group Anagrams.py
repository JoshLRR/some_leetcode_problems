from typing import List
from collections import Counter
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        wordMap = {}
        # ans = []
        for word in strs:
            sortedWord = ''.join(sorted(word))
            if sortedWord not in wordMap:
                wordMap[sortedWord] = [word]
            else:
                wordMap[sortedWord].append(word)

        # for words in wordMap.items():
        #     ans.append(words[1])

        print(list(wordMap.values()))
        return list(wordMap.values())


strs1 = ["eat","tea","tan","ate","nat","bat"]
ans1 = [["bat"],["nat","tan"],["ate","eat","tea"]]
assert Solution().groupAnagrams(strs1) == ans1, "Test failed!"

strs2 = [""]
ans2 = [[""]]
assert Solution().groupAnagrams(strs2) == ans2, "Test failed!"

strs3 = ["a"]
ans3 = [["a"]]
assert Solution().groupAnagrams(strs3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")