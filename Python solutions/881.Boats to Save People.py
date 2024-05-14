import time
from typing import List

class Solution:
    def numRescueBoats(self, people, limit):
        people.sort()   
        left = 0
        right = len(people) - 1
        boatCount = 0

        while left <= right:
            currWeight = people[left] + people[right]
            if currWeight > limit:
                right -= 1
                boatCount += 1
            elif currWeight <= limit:
                boatCount += 1
                right -= 1
                left += 1

        print(boatCount)
        return boatCount
    
"""
Two pointer --
First sort, then check each pair of weights (people[left] + people[right])
If the current weight exceeds the limit, move only the right-side pointer and increment the boat count by 1
If the current weight is less than or equal to the limit, we can put both left and right passengers on the boat. Increment the left pointer, decrement the right pointer, and increase the boat count.

Return the boat count
"""
    

people1 = [1,2]
limit1 = 3
ans1 = 1
people2 = [3,2,2,1]
limit2 = 3
ans2 = 3
people3 = [3,5,3,4]
limit3 = 5
ans3 = 4
people4 = [5,1,4,2]
limit4 = 6
ans4 = 2
t0 = time.time()
assert Solution().numRescueBoats(people1, limit1) == ans1, "Test failed!"
assert Solution().numRescueBoats(people2, limit2) == ans2, "Test failed!"
assert Solution().numRescueBoats(people3, limit3) == ans3, "Test failed!"
assert Solution().numRescueBoats(people4, limit4) == ans4, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")