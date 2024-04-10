from typing import List

# class Solution:
#     def minimumLevels(self, possible: List[int]) -> int:
#         if len(possible) == 2 and possible[0] == possible[1]:
#             return-1
        
#         minGamesPlayed = float('inf')
#         for i in range(len(possible)):
#             danielScore = 0
#             bobScore = 0
#             for j in range(i):
#                 if possible[j] == 0:
#                     danielScore -= 1
#                 else:
#                     danielScore += 1
#             for k in range(i, len(possible)):
#                 if possible[k] == 0:
#                     bobScore -= 1
#                 else:
#                     bobScore += 1
            
#             if danielScore > bobScore and i is not 0:
#                 print(i, danielScore, bobScore)
#                 minGamesPlayed = min(minGamesPlayed, i)
#         # print("Returning -1")
#         print(f"minGamesPlayed: {minGamesPlayed}")
#         if minGamesPlayed == float('inf'):
#             return -1
#         else:
#             return minGamesPlayed

class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        # Special case check
        if len(possible) == 2 and possible[0] == possible[1]:
            return -1

        # Convert the possible list to scores directly (-1 for 0, +1 for 1)
        scores = [1 if score else -1 for score in possible]

        # Precompute total score to help in calculating running totals
        totalScore = sum(scores)

        danielScore, bobScore = 0, totalScore
        minGamesPlayed = float('inf')

        for i, score in enumerate(scores):
            danielScore += score
            bobScore -= score

            # We use i+1 to ensure Daniel has played at least one game
            # before comparing scores, avoiding comparison on the initial state
            if danielScore > bobScore and i+1 < len(scores):
                minGamesPlayed = min(minGamesPlayed, i + 1)
        
        return -1 if minGamesPlayed == float('inf') else minGamesPlayed

    

assert Solution().minimumLevels([1,0,1,0]) == 1, "Test failed!"
assert Solution().minimumLevels([1,1,1,1,1]) == 3, "Test failed!"
assert Solution().minimumLevels([0,0]) == -1, "Test failed!"
assert Solution().minimumLevels([0,0,0]) == 1, "Test failed!"




print("\033[32mAll tests passed!\033[0m\n")