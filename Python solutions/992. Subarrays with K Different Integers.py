from typing import List
from collections import defaultdict
from collections import Counter
class Solution:
    def subarraysWithKDistinct(self, A, K):
        return self.atMostK(A, K) - self.atMostK(A, K - 1)

    def atMostK(self, A, K):
        count = Counter()
        res = i = 0
        for j in range(len(A)):
            if count[A[j]] == 0: K -= 1
            count[A[j]] += 1
            while K < 0:
                count[A[i]] -= 1
                if count[A[i]] == 0: K += 1
                i += 1
            res += j - i + 1
        
        return res
    
"""
Brute force approach:
- Create a window of size k, slide it until the end
- Increment window size by 1, slide it until the end
- Repeat until window size is size of nums
    For every window, check to see that each int count is not more than one
"""

nums1 = [1,2,1,2,3]
k1 = 2
ans1 = 7
assert Solution().subarraysWithKDistinct(nums1, k1) == ans1, "Test failed!"

nums2 = [1,2,1,3,4]
k2 = 3
ans2 = 3
assert Solution().subarraysWithKDistinct(nums2, k2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")