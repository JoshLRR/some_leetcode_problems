from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        currTank = 0
        totalTank = 0
        startingIndex = 0

        for i, station in enumerate(gas):
            currTank += station - cost[i]
            totalTank += station - cost[i]

            if currTank < 0:
                startingIndex = i + 1
                currTank = 0

        if totalTank < 0:
            print("Returning -1")
            return -1
        else:
            print(startingIndex)
            return startingIndex


"""
    Instead of an O(n^2) solution where you start from every index and do a full loop, we can do this in one pass

    Keep track of current tank level, total tank level, and the starting index
    The total tank level keeps track of how much fuel it takes for a round trip, if this is under 0 it's not possible to do a round trip.
    The current tank level helps us find the starting index, if this ever drops below 0, we reset the tank level to 0 and the startingStation is set to the next station

"""

gas1 = [1,2,3,4,5]
cost1 = [3,4,5,1,2]        
ans1 = 3
assert Solution().canCompleteCircuit(gas1, cost1) == ans1, "Test failed!"

gas2 = [2,3,4]
cost2 = [3,4,3]        
ans2 = -1
assert Solution().canCompleteCircuit(gas2, cost2) == ans2, "Test failed!"

gas3 = [5,1,2,3,4]
cost3 = [4,4,1,5,1]
ans3 = 4
assert Solution().canCompleteCircuit(gas3, cost3) == ans3, "Test failed!"


print("\033[32mAll tests passed!\033[0m\n")