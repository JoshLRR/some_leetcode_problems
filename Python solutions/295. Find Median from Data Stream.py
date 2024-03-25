import heapq

import heapq

class MedianFinder:

    def __init__(self):
        self.maxHeap = []
        self.minHeap = []

    def addNum(self, num: int) -> None:
        if not self.maxHeap or num <= -self.maxHeap[0]:
            heapq.heappush(self.maxHeap, -num)
        else:
            heapq.heappush(self.minHeap, num)

        # Rebalance heaps if necessary to maintain the property that maxHeap is either equal in size to minHeap or has one extra element
        if len(self.maxHeap) > len(self.minHeap) + 1:
            heapq.heappush(self.minHeap, -heapq.heappop(self.maxHeap))
        elif len(self.maxHeap) < len(self.minHeap):
            heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))

    def findMedian(self) -> float:
        if len(self.maxHeap) == len(self.minHeap):
            return (-self.maxHeap[0] + self.minHeap[0]) / 2.0
        else:
            return -self.maxHeap[0]



"""
To find median, use a max heap to store the lower half of nums
    use min heap to store the higher half of nums
Ex
    Max heap: 1  2 3 4 5
    Min heap: 10 9 8 7 6
    --------------------
    Median: (5 + 6) / 2 = 11 / 2 = 5.5
    That way the median can be found in O(1) time by taking the top of each


"""
        

assert Solution(). == , "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")