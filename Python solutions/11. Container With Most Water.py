class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxArea = float('-inf')

        while left < right:
            currArea = (right - left) * min(height[left], height[right])
            maxArea = max(currArea, maxArea)

            if height[right] > height[left]:
                left += 1
            else:
                right -= 1

        return maxArea


assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")