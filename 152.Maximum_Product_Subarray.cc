#include <iostream>
#include <cassert>
#include <vector> 

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int maxSoFar = nums[0];
        int maxHere = nums[0];
        int minHere = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                std::swap(maxHere, minHere);
            }

            maxHere = std::max(nums[i], maxHere *= nums[i]);
            minHere = std::min(nums[i], minHere *= nums[i]);

            maxSoFar = std::max(maxHere, maxSoFar);
        }

        return maxSoFar;
    }
};

/*
    We have to deal with an unknown number of negative numbers and need to account that a negative * a positive makes it smaller, and two negatives makes the product bigger. To account for this, we keep track of both the max value and min value we've encountered so far.

    As we iterate through the nums array, we check if the current num is negative. If it's negative, we swap our max and min values since the product of two negatives will be positive.

    Calculate new max and mins for the current index
    For both, we compare against the current value because if we suddenly run into a larger value than our running count, then we reset the checked subarray by assigning max to the curr value.

    Calculate new max up to the current index
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {2,3,-2,4};
    int ans1 = 6;
    assert(solution.maxProduct(nums1) == ans1);

    std::vector<int> nums2 = {-2,0,-1};
    int ans2 = 0;
    assert(solution.maxProduct(nums2) == ans2);

    std::vector<int> nums3 = {-3,-1,-1};
    int ans3 = 3;
    assert(solution.maxProduct(nums3) == ans3);

    std::vector<int> nums4 = {0,2};
    int ans4 = 2;
    assert(solution.maxProduct(nums4) == ans4);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}