#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <algorithm>

class Solution {
public:
    // int heightChecker(std::vector<int>& heights) {
    //     std::vector<int> expected = heights;
    //     std::sort(expected.begin(), expected.end());
    //     int noMatch = 0;

    //     for (int idx = 0; idx < heights.size(); ++idx) {
    //         if (heights[idx] != expected[idx]) ++noMatch;
    //     }

    //     return noMatch;
    // }
    int heightChecker(std::vector<int>& heights) {
        if (heights.size() < 2) return 0;

        std::vector<int> map(101, 0);

        for (int height : heights) {
            ++map[height];
        }

        int ans = 0, hPointer = 0;

        for (int height : heights) {
            while (map[hPointer] == 0) ++hPointer;

            if (height != hPointer) ++ans;

            --map[hPointer];
        }

        return ans;
    }
};

/*
    Solution 1: O(log n) -- Very basic, create a copy of the heights array and sort it. Then directly compare elements and count the number of elements that don't match.

    Solution 2: O(n) -- Counting Sort
    Heights range from 1 to 100, count the occurence of each height seen
    In a second loop, we go through each height. If the current evaluated height is 0, we know that height isn't relevant so we can keep increasing the pointer of our map.
    Once we find a map height that isn't 0, check to see if the current height is the same as the h pointer. If they're the same, we've found a match and can decrement the count. Otherwise, we can increment our count of no matches.
*/

int main() {
    Solution solution;
    std::vector<int> heights1 = {1,1,4,2,1,3};
    std::vector<int> heights2 = {5,1,2,3,4};
    std::vector<int> heights3 = {1,2,3,4,5};
    int ans1 = 3;
    int ans2 = 5;
    int ans3 = 0;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.heightChecker(heights1);
    int test2 = solution.heightChecker(heights2);
    int test3 = solution.heightChecker(heights3);
    auto end = std::chrono::high_resolution_clock::now();
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}