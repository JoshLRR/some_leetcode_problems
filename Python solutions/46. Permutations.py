from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def findPermutation(startIndex: int):
            if startIndex == len(nums):
                ans.append(nums[:])
            
            for i in range(startIndex, len(nums)):
                nums[i], nums[startIndex] = nums[startIndex], nums[i]
                findPermutation(startIndex + 1)
                nums[i], nums[startIndex] = nums[startIndex], nums[i]
                
        findPermutation(0)
        # print(ans)
        return ans


nums1 = [1,2,3]
ans1 = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
assert Solution().permute(nums1) == ans1, "Test failed!"

nums2 = [0,1]
ans2 = [[0,1],[1,0]]
assert Solution().permute(nums2) == ans2, "Test failed!"

nums3 = [1]
ans3 = [[1]]
assert Solution().permute(nums3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")