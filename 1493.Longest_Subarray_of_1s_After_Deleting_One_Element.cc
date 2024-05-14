#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int left = 0;
        int ans = 0;
        std::array<int, 2> encountered = {0,0};
        bool noZeroes = true;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) noZeroes = false;

            ++encountered[nums[right]];

            while (encountered[0] > 1) {
                --encountered[nums[left]];
                ++left;
            }

            ans = std::max(ans, right - left);
        }

        if (noZeroes) return nums.size() - 1;

        std::cout << ans << "\n";
        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,1,0,1};
    int ans1 = 3;
    std::vector<int> nums2 = {0,1,1,1,0,1,1,0,1};
    int ans2 = 5;
    std::vector<int> nums3 = {1,1,1};
    int ans3 = 2;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.longestSubarray(nums1) == ans1);
    assert(solution.longestSubarray(nums2) == ans2);
    assert(solution.longestSubarray(nums3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}