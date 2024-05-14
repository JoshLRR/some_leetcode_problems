#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        // std::sort(nums1.begin(), nums1.end());
        // std::sort(nums2.begin(), nums2.end());

        // return nums2[0] - nums1[0];

        int min1 = *std::min_element(nums1.begin(), nums1.end());
        int min2 = *std::min_element(nums2.begin(), nums2.end());

        return min2 - min1;
    }
};
/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {2,6,4};
    std::vector<int> nums2 = {9,7,5};
    int ans1 = 3;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.addedInteger(nums1, nums2) == ans1);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}