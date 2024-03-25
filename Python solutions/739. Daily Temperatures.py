from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [0] * len(temperatures)
        tempStack = [] # pairs of [temp, index]

        for i, temp in enumerate(temperatures):
            while tempStack and tempStack[-1][0] < temp:
                stackTemp, stackIdx = tempStack.pop()
                ans[stackIdx] = i - stackIdx
            tempStack.append([temp, i])
        
        return ans


temperatures1 = [73,74,75,71,69,72,76,73]
ans1 = [1,1,4,2,1,1,0,0]
assert Solution().dailyTemperatures(temperatures1) == ans1, "Test failed!"

temperatures2 = [30,40,50,60]
ans2 = [1,1,1,0]
assert Solution().dailyTemperatures(temperatures2) == ans2, "Test failed!"

temperatures3 = [30,60,90]
ans3 = [1,1,0]
assert Solution().dailyTemperatures(temperatures3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")