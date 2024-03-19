from typing import List

# Recursion with backtracking
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        currCombo = []
        ans = []
        def dfs(currIndex: [int], currCombo: List[int]) -> None:
            currSum = sum(currCombo)
            
            if currSum == target:
                ans.append(currCombo.copy())
                return
            elif currSum > target:
                return

            for i in range(currIndex, len(candidates), 1):
                currCombo.append(candidates[i])
                dfs(i, currCombo)
                currCombo.pop()
        
        dfs(0, currCombo)
        return ans


candidates1 = [2,3,6,7] 
target1 = 7
ans1 = [[2,2,3],[7]]
assert Solution().combinationSum(candidates1, target1) == ans1, "Test failed!"

candidates2 = [2,3,5]
target2 = 8
ans2 = [[2,2,2,2],[2,3,3],[3,5]]
assert Solution().combinationSum(candidates2, target2) == ans2, "Test failed!"

candidates3 = [2]
target3 = 1
ans3 = []
assert Solution().combinationSum(candidates3, target3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")