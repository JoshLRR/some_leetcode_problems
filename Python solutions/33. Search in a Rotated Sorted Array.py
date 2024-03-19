class Solution:
    def search(self, nums: List[int], target: int) -> int:

            
                
                


nums1 = [4,5,6,7,0,1,2]
target1 = 0
ans1 = 4
assert Solution().search(nums1, target1) == ans1, "Test failed!"

nums2 = [4,5,6,7,0,1,2]
target2 = 3
ans2 = -1
assert Solution().search(nums2, target2) == ans2, "Test failed!"

nums3 = [1]
target3 = 0
ans3 = -1
assert Solution().search(nums3, target3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")