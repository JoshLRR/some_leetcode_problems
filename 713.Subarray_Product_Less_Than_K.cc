#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

class Solution {
public:
    // Brute force approach with recursion + backtracking
    // void generateSubarrays(std::vector<std::vector<int>>& ans, std::vector<int> currCombo, int k, int currIndex, std::vector<int> nums) {
    //     if (currIndex >= nums.size()) return;
    //     currCombo.push_back(nums[currIndex]);
    //     int runningProduct = std::accumulate(currCombo.begin(), currCombo.end(), 1, std::multiplies<int>());

    //     if (runningProduct < k) {
    //         ans.push_back(currCombo);
    //         generateSubarrays(ans, currCombo, k, currIndex + 1, nums);
    //     }
    // }

    // int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    //     if (k == 0) return 0;
    //     std::vector<std::vector<int>> ans;

    //     for (int i = 0; i < nums.size(); ++i) {
    //         generateSubarrays(ans, {}, k, i, nums);
    //     }
    //     for (auto& subarray: ans) {
    //         for (auto& num : subarray) {
    //             std::cout << num << " ";
    //         }
    //         std::cout << "\n";
    //     }
    //     return ans.size();
    // }

    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int count = 0;
        int product = 1;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left++];
            }
            count += right - left + 1;
        }

        return count;
    }
};
/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {10,5,2,6};
    int k1 = 100;
    int ans1 = 8;
    assert(solution.numSubarrayProductLessThanK(nums1, k1) == ans1);

    std::vector<int> nums2 = {1,2,3};
    int k2 = 0;
    int ans2 = 0;
    assert(solution.numSubarrayProductLessThanK(nums2, k2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}