#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; ++i) {
            for (auto& num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }

        for (auto& num : dp) {
            std::cout << num << " "; 
        }
        std::cout << "\n";

        return dp[target];
    }
};

/*
    Create dp table to represent combination counts for each value up to and including target
    For a target of 4, it would start as 
    0   1   2   3   4   
    1   0   0   0   0       -- 0 starts with 1 because you don't need any nums to make 0
                                Then we iterate from 0 -> target
    1   1   0   0   0
    1   1   2   0   0
    1   1   2   4   0
    1   1   2   4   7
    For each num in nums, if its value is less than i or equal to i, we can add dp[i - num] to dp[i], which is building each answer from the number of solutions for previous values
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {1,2,3};
    int tar1 = 5;
    int ans1 = 13;
    assert(solution.combinationSum4(nums1, tar1) == ans1);

    std::vector<int> nums2 = {9};
    int tar2 = 3;
    int ans2 = 0;
    assert(solution.combinationSum4(nums2, tar2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}