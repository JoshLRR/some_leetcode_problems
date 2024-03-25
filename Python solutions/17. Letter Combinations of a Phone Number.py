from typing import List

class Solution:
    def __init__(self):
        self.digitLetterMap = {
            "2" : {"a", "b", "c"},
            "3" : {"d", "e", "f"},
            "4" : {"g", "h", "i"},
            "5" : {"j", "k", "l"},
            "6" : {"m", "n", "o"},
            "7" : {"p", "q", "r", "s"},
            "8" : {"t", "u", "v"},
            "9" : {"w", "x", "y", "z"}
        }

    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        ans = []

        def createCombination(currCombo, nextDigits) -> None:
            if not nextDigits:
                ans.append(currCombo)
                return

            for letter in self.digitLetterMap[nextDigits[0]]:
                createCombination(currCombo + letter, nextDigits[1:])
        
        createCombination("", digits)
        # print(ans)
        return ans
        

digits1 = "23"
ans1 = ["ad","ae","af","bd","be","bf","cd","ce","cf"]

digits2 = ""
ans2 = []

digits3 = "2"
ans3 = ["a","b","c"]

assert Solution().letterCombinations(digits1) == ans1, "Test failed!"
assert Solution().letterCombinations(digits2) == ans2, "Test failed!"
assert Solution().letterCombinations(digits3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")