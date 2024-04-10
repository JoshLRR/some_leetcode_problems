import heapq
from typing import List
from collections import defaultdict

class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        encountered = defaultdict(int)
        n = len(nums)
        heap = []
        ans = [0] * n

        for i, (num, frequency) in enumerate(zip(nums, freq)):
            encountered[num] += frequency
            heapq.heappush(heap, [-encountered[num], num])  # freq, num

            while heap and -heap[0][0] != encountered[heap[0][1]]: # If the frequency count in the heap does not match what's stored in the map, we can pop it 
                heapq.heappop(heap)
            if heap:
                ans[i] = -heap[0][0]
        
        return ans
"""
    Use a 
"""
    
nums1 = [2,3,2,1]
freq1 = [3,2,-3,1]        
ans1 = [3,3,2,2]
assert Solution().mostFrequentIDs(nums1, freq1) == ans1, "Test failed!"

nums2 = [5,5,3]
freq2 = [2,-2,1]        
ans2 = [2,0,1]
assert Solution().mostFrequentIDs(nums2, freq2) == ans2, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")