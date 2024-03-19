class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        cumSum = 1
        numsLength = len(nums)
        ans = [1] * numsLength
        for i in range(0, numsLength):
            ans[i] = cumSum
            cumSum *= nums[i]
        
        cumSum = 1
        for i in range(numsLength - 1, -1, -1):
            ans[i] *= cumSum
            cumSum *= nums[i]

        # print(ans)
        return ans

nums1 = [1,2,3,4]
ans1 = [24,12,8,6]
assert Solution().productExceptSelf(nums1) == ans1, "Test failed!"

nums1 = [-1,1,0,-3,3]
ans1 = [0,0,9,0,0]
assert Solution().productExceptSelf(nums1) == ans1, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")