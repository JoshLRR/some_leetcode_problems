#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>

class Solution {
public:
    // O(n^2) solution
    // bool checkSubarraySum(std::vector<int>& nums, int k) {
    //     int n = nums.size();

    //     for (int idx = 0; idx < n; ++idx) {
    //         int prefixSum = nums[idx];

    //         for (int jdx = idx + 1; jdx < n; ++jdx) {
    //             prefixSum += nums[jdx];
    //             if (prefixSum % k == 0) {
    //                 return true;
    //             }
    //         }
    //     }

    //     return false;
    // }

    bool checkSubarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> remainderIndexMap;
        remainderIndexMap[0] = -1;
        int prefixSum = 0;

        for (int idx = 0; idx < nums.size(); ++idx) {
            prefixSum += nums[idx];
            int remainder = prefixSum % k;

            if (remainderIndexMap.find(remainder) != remainderIndexMap.end()) {
                if (idx - remainderIndexMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndexMap[remainder] = idx;
            }
        }

        return false;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {23,2,4,6,7};
    std::vector<int> nums2 = {23,2,6,4,7};
    std::vector<int> nums3 = {23,2,6,4,7};
    int k1 = 6;
    int k2 = 6;
    int k3 = 13;
    bool ans1 = true;
    bool ans2 = true;
    bool ans3 = false;

    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.checkSubarraySum(nums1, k1);
    bool test2 = solution.checkSubarraySum(nums2, k2);
    // bool test3 = solution.checkSubarraySum(nums3, k3);
    auto end = std::chrono::high_resolution_clock::now();
    assert(test1 = ans1);
    assert(test2 = ans2);

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 3e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}