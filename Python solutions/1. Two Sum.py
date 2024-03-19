class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        encountered = {}
        for i, num in enumerate(nums):
            if target - num in encountered:
                # print (encountered[target-num],i)
                return [encountered[target - num],i] 
            else:
                encountered[num] = i



nums1 = [2,7,11,15] 
target1 = 9
ans1 = [0,1]
assert Solution().twoSum(nums1, target1) == ans1, "Test failed!"

nums2 = [3,2,4] 
target2 = 6
ans2 = [1,2]
assert Solution().twoSum(nums2, target2) == ans2, "Test failed!"

nums3 = [3,3] 
target3 = 6
ans3 = [0,1]
assert Solution().twoSum(nums3, target3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")