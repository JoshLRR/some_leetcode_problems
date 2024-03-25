from typing import List
import heapq
from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        ans = []
        wordCounts = Counter(words)
        wordHeap = []

        for word, count in wordCounts.items():
            heapq.heappush(wordHeap, (-count, word))

        for i in range(k):
            count, word = heapq.heappop(wordHeap)
            ans.append(word)
            
        # print(ans)
        return ans


words1 = ["i","love","leetcode","i","love","coding"]
k1 = 2
ans1 = ["i","love"]
assert Solution().topKFrequent(words1,k1) == ans1, "Test failed!"

words2 = ["the","day","is","sunny","the","the","the","sunny","is","is"]
k2 = 4
ans2 = ["the", "is", "sunny", "day"]
assert Solution().topKFrequent(words2,k2) == ans2, "Test failed!"



print("\033[32mAll tests passed!\033[0m\n")