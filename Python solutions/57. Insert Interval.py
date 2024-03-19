from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []
        idx = 0
        while idx < len(intervals) and intervals[idx][1] < newInterval[0]:
            ans.append(intervals[idx])
            idx += 1
        
        while idx < len(intervals) and newInterval[1] >= intervals[idx][0]:
            newInterval[0] = min(intervals[idx][0], newInterval[0])
            newInterval[1] = max(intervals[idx][1], newInterval[1])
            idx += 1
        
        ans.append(newInterval)
        while idx < len(intervals):
            ans.append(intervals[idx])
            idx += 1

        print(ans)
        return ans
            



# Test 1: Example 1
assert Solution().insert([[1,3],[6,9]], [2,5]) == [[1,5],[6,9]], "Test 1 failed!"

# Test 2: Example 2
assert Solution().insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]) == [[1,2],[3,10],[12,16]], "Test 2 failed!"

# Test 3: Empty intervals
assert Solution().insert([], [5,7]) == [[5,7]], "Test 3 failed!"

# Test 4: No overlap, new interval at the end
assert Solution().insert([[1,2],[3,4]], [5,6]) == [[1,2],[3,4],[5,6]], "Test 4 failed!"

# Test 5: No overlap, new interval at the start
assert Solution().insert([[2,3],[4,5]], [0,1]) == [[0,1],[2,3],[4,5]], "Test 5 failed!"

# Test 6: New interval overlaps with all intervals
assert Solution().insert([[1,2],[3,4],[5,6]], [2,5]) == [[1,6]], "Test 6 failed!"

# Test 7: New interval is within an existing interval
assert Solution().insert([[1,5]], [2,3]) == [[1,5]], "Test 7 failed!"

# Test 8: New interval extends an existing interval on both sides
assert Solution().insert([[1,2],[3,5],[6,7]], [2,6]) == [[1,7]], "Test 8 failed!"

print("\033[32mAll tests passed!\033[0m\n")
