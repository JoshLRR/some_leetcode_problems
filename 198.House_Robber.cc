#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        std::vector<int> dp(2, 0);

        for (int i = 0; i < nums.size(); ++i) {
            int temp = std::max(nums[i] + dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = temp;
        }

        return dp[1];
    }
};

/*
    Dynamic Programming
    

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,2,3,1};
    int ans1 = 4;
    assert(solution.rob(nums1) == ans1);

    std::vector<int> nums2 = {2,7,9,3,1};
    int ans2 = 12;
    assert(solution.rob(nums2) == ans2);

    std::vector<int> nums3 = {2,1,1,2};
    int ans3 = 4;
    assert(solution.rob(nums3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}