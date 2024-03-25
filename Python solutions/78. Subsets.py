from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # nums.sort()
        ans = []

        def dfs(index, path):
            ans.append(path)

            for i in range(index, len(nums)):
                dfs(i + 1, path + [nums[i]])
            
            
        
        dfs(0, [])
        print(ans)
        return ans

nums1 = [1,2,3]
ans1 = [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
assert Solution().subsets(nums1) == ans1, "Test failed!"

nums2 = [0]
ans2 = [[],[0]]

print("\033[32mAll tests passed!\033[0m\n")