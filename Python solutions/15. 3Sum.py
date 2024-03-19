from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)

        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            target = -nums[i]
            left = i + 1
            right = n - 1

            while left < right:
                currSum = nums[left] + nums[right]

                if currSum > target:
                    right -= 1
                elif currSum < target:
                    left += 1
                else:
                    ans.append([nums[i], nums[left], nums[right]])

                    while (left < right and nums[left] == nums[left + 1]):
                        left += 1
                    left += 1
                    while (left < right and nums[right] == nums[right - 1]):
                        right -= 1
                    right -= 1

        
        print(ans)
        return ans

nums1 = [-1,0,1,2,-1,-4]
ans1 = [[-1,-1,2],[-1,0,1]]
assert Solution().threeSum(nums1) == ans1, "Test failed!"

nums2 = [0,1,1]
ans2 = []
assert Solution().threeSum(nums2) == ans2, "Test failed!"

nums3 = [0,0,0]
ans3 = [[0,0,0]]
assert Solution().threeSum(nums3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")