#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm> 
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    ++dp[i];
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

/*
    Dynamic programming approach --
    For each value, we check the values before it (to the left) using a nested for loop
    If the current value (From outer loop) is larger than the left value AND its value in the dp table shows an increase, we change the dp table value
    Return the max element
    Time complexity -- O(n^2)
    Space complexity -- O(n) for dp table

    Binary search approach --
    Use an auxiliary vector to store sequences, we'll call tails
    Compare each value to the back, if the curr value is lower
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {10,9,2,5,3,7,101,18};
    int ans1 = 4;
    assert(solution.lengthOfLIS(nums1) == ans1);

    std::vector<int> nums2 = {0,1,0,3,2,3};
    int ans2 = 4;
    assert(solution.lengthOfLIS(nums2) == ans2);

    std::vector<int> nums3 = {7,7,7,7,7,7,7};
    int ans3 = 1;
    assert(solution.lengthOfLIS(nums3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}