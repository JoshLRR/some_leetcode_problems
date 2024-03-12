#include <iostream>
#include <cassert>
#include <queue>
class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        } else {
            return (double)maxHeap.top();
        }
    }
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int numVals = 0;
};

/*
    Split the values into two heaps, one max and one min
    If odd num of values, the val at the top of the max heap will be the median
    If even, the median is the average of the top of the max and min heap

    eg. 1 2 3
    max 1 2
    min 3
    median = 2

    eg 1 2 3 4
    max 1 2
    min 4 3
    median = 2 + 3 / 2 = 2.5 
*/

int main() {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    assert(mf.findMedian() == 1.5);
    mf.addNum(3);
    assert(mf.findMedian() == 2.0);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}