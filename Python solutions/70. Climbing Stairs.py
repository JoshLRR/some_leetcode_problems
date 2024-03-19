class Solution:
    def climbStairs(self, n: int) -> int:
        steps = [1,2]

        if n == 1: return steps[0]

        for i in range(2, n):
            if i % 2 == 0:
                steps[0] = steps[0] + steps[1]
            else:
                steps[1] = steps[0] + steps[1]
        
        return max(steps[0], steps[1])

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")