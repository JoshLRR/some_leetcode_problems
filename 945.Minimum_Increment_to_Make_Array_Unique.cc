#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <algorithm>

class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::sort(nums.begin(), nums.end());
        
        int increments = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= prev) {
                increments += (prev + 1 - nums[i]);
                prev = prev + 1;
            } else {
                prev = nums[i];
            }
        }

        return increments;
    }
};


/*
    - Sort array
    - Get largest val, create array to the size of largest value
    - Iterate through the counting sort array, keep track of last seen 0 count
    - While there's a duplicate count greater than 1, add the difference of the index to that and the last seen 0 
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,2,2};
    int ans1 = 1;
    std::vector<int> nums2 = {3,2,1,2,1,7};
    int ans2 = 6;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.minIncrementForUnique(nums1);
    int test2 = solution.minIncrementForUnique(nums2);
    auto end = std::chrono::high_resolution_clock::now();
    assert (test1 == ans1);
    assert (test2 == ans2);
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}