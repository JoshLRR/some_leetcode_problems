from collections import Counter
from typing import List
import heapq
from collections import deque
# class Solution:
    # def leastInterval(self, tasks: List[str], n: int) -> int:
    #     freq = list(Counter(tasks).values())
    #     maxFreq = max(freq)
    #     maxFreqCount = freq.count(maxFreq)

    #     ans = (maxFreq - 1) * (n + 1) + maxFreqCount

    #     return max(ans, len(tasks))

class Solution:
    def leastInterval(self, tasks: [str], n: int) -> int:
        freq_map = Counter(tasks)
        maxHeap = [-frequency for frequency in freq_map.values()]
        heapq.heapify(maxHeap)

        currTime = 0
        queue = deque()

        while maxHeap or queue:
            currTime += 1
            
            if maxHeap:
                frequency = 1 + heapq.heappop(maxHeap)
                if frequency:
                    queue.append([frequency, currTime + n])
            if queue and queue[0][1] <= currTime:
                heapq.heappush(maxHeap, queue.popleft()[0])

        # print(currTime)
        return currTime


"""
A lot faster/simpler to just use math to calculate the intervals passed than simulating the flow

Otherwise, use a combination of a hash map, max heap, and a queue. Count the frequency of each task, then add every task:timesToBeRun to a maxHeap. We run tasks with the highest timesToBeRun first, so they'll be at the top of the heap. Then, we push run tasks into a queue, of which we also track the time at which they can be popped from the queue and add it back to the heap.

We do this while both the queue and heap have values left, and then return currTime
"""
        
tasks1 = ["A","A","A","B","B","B"] 
n1 = 2
ans1 = 8
assert Solution().leastInterval(tasks1, n1) == ans1, "Test failed!"

tasks2 = ["A","C","A","B","D","B"] 
n2 = 1 
ans2 = 6
assert Solution().leastInterval(tasks2, n2) == ans2, "Test failed!"

tasks3 = ["A","A","A", "B","B","B"]
n3 = 3
ans3 = 10
assert Solution().leastInterval(tasks3, n3) == ans3, "Test failed!"

print("\033[32mAll tests passed!\033[0m\n")