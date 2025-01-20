#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <algorithm>

class CustomStack {
public:
    int maxSize1;
    std::vector<int> stackArr;

    CustomStack(int maxSize) {
        maxSize1 = maxSize;
    }
    
    void push(int x) {
        if (stackArr.size() < maxSize1) {
            stackArr.push_back(x);
        }
    }
    
    int pop() {
        if (stackArr.size() > 0) {
            int numToReturn = stackArr[stackArr.size() - 1];
            stackArr.pop_back();
            return numToReturn;
        } 

        return -1;  // Stack is empty, return -1
    }
    
    void increment(int k, int val) {
        int numToIncrement = std::min(k, (int)stackArr.size()); // If stackSize is less than k, increment only stackSize nums

        for (int idx = 0; idx < numToIncrement; ++idx) {
            stackArr[idx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

/*

*/

int main() {
    Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}