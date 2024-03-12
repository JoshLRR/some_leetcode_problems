#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSoFar = INT_MIN;
        int maxHere = 0;

        for (auto& num : nums) {
            maxHere = maxHere + num;
            maxSoFar = std::max(maxSoFar, maxHere);
            if (maxHere < 0) maxHere = 0;
            // std::cout << maxSoFar << " ";
        }

        return maxSoFar;
    }
};

/*
    Kadane's Algorithm
    Keep track of max so far and max here, where here is the curr value
    if maxHere < 0, reset it to 0 to "shrink" the window to the next value

    Time complexity: O(n)
    Space complexity: O(1)
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    int ans1 = 6;
    assert(solution.maxSubArray(nums1) == ans1);

    std::vector<int> nums2 = {1};
    int ans2 = 1;
    assert(solution.maxSubArray(nums2) == ans2);

    std::vector<int> nums3 = {5,4,-1,7,8};
    int ans3 = 23;
    assert(solution.maxSubArray(nums2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}