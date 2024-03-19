from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if not prerequisites: return True
        visiting = set()
        courseMap = {i: [] for i in range(numCourses)}

        for course, prereq in prerequisites:
            courseMap[course].append(prereq)
            if course == prereq: return False

        def dfs(course) -> bool:
            # nonlocal visiting
            # nonlocal courseMap
            if course in visiting:
                return False
            if not courseMap[course]: return True

            visiting.add(course)
            for prereq in courseMap[course]:
                if not dfs(prereq): return False

            visiting.remove(course)
            courseMap[course] = []

            return True

        for course in courseMap.keys():
            if not dfs(course): return False

        return True


# Test Case 1: No prerequisites
assert Solution().canFinish(2, []) == True, "Test failed for no prerequisites."

# Test Case 2: Linear Dependency Chain
assert Solution().canFinish(3, [[1,0], [2,1]]) == True, "Test failed for linear dependency chain."

# Test Case 3: Cyclic Dependency
assert Solution().canFinish(2, [[1,0], [0,1]]) == False, "Test failed for cyclic dependency."

# Test Case 4: Multiple Independent Cycles
assert Solution().canFinish(4, [[0,1], [1,2], [2,0], [3,0]]) == False, "Test failed for multiple independent cycles."

# Test Case 5: Complex Dependencies
assert Solution().canFinish(4, [[0,1], [2,1], [3,2], [1,3]]) == False, "Test failed for complex dependencies."

# Test Case 6: Maximum Constraints
# This is a synthetic example meant to test the function's efficiency. 
# The actual prerequisites list should be constructed to reflect the maximum constraints without exceeding them.
numCourses_max = 2000
prerequisites_max = [[i, (i+1) % numCourses_max] for i in range(5000)]
assert Solution().canFinish(numCourses_max, prerequisites_max) == False, "Test failed for maximum constraints."

print("\033[32mAll tests passed!\033[0m\n")
