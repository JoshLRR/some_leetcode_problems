import time
from typing import List
from collections import deque

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        n = len(deck)
        ans = [0] * n
        indices = deque(range(n))
        
        for card in deck:
            idx = indices.popleft()
            ans[idx] = card
            if indices:
                indices.append(indices.popleft())
        
        # print(ans)
        return ans
        


deck1 = [17,13,11,2,3,5,7]
ans1 = [2,13,3,11,5,17,7]
deck2 = [1,1000]
ans2 = [1,1000]
t0 = time.time()
assert Solution().deckRevealedIncreasing(deck1) == ans1, "Test failed!"
assert Solution().deckRevealedIncreasing(deck2) == ans2, "Test failed!"
t1 = time.time()
elapsed = t1 - t0
print(f"\033[32mAll tests passed in {elapsed * 1000} milliseconds!\033[0m\n")


# print("\033[32mAll tests passed!\033[0m\n")