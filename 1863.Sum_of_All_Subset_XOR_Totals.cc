#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    // int subsetXORSum(std::vector<int>& nums) {
    //     int n = nums.size();
    //     int numSubsets = std::pow(2, n);
    //     int ans = 0;

    //     for (int subset = 1; subset < numSubsets; ++subset) {
    //         int runningXor = 0;
    //         for (int idx = 0, bits = subset; idx < n; ++idx, bits >>= 1) {
    //             if (bits & 1) {
    //                 runningXor ^= nums[idx];
    //             }
    //         }

    //         ans += runningXor;
    //     }        

    //     return ans;
    // }
    int subsetXORSum(const std::vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        int subsetsCount = 1 << n; // 2^n subsets

        // Iterate over each bit position (0 to 19 since nums[i] <= 20)
        for (int bit = 0; bit < 20; ++bit) {
            int bitSum = 0;
            for (int num : nums) {
                if (num & (1 << bit)) { // Check if the bit is set in num
                    bitSum++;
                }
            }
            if (bitSum > 0) {
                // Add the contribution of this bit to the total sum
                totalSum += (1 << bit) * (subsetsCount / 2);
            }
        }
        return totalSum;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {1,3};
    int ans1 = 6;
    std::vector<int> nums2 = {5,1,6};
    int ans2 = 28;
    std::vector<int> nums3 = {3,4,5,6,7,8};
    int ans3 = 480;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.subsetXORSum(nums1) == ans1);
    assert(solution.subsetXORSum(nums2) == ans2);
    assert(solution.subsetXORSum(nums3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}