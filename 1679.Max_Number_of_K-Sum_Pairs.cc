#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = 0;

        std::sort(nums.begin(), nums.end());

        while (left < right) {
            int curr = nums[left] + nums[right];
            if (curr < k) {
                ++left;
            } else if (curr > k) {
                --right;
            } else {
                ++ans;
                ++left;
                --right;
            }
        }

        return ans;
    }
};

/*
    Can be optimized for time complexity by using a hash map. Then the problem basically becomes 2sum
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {1,2,3,4};
    int k1 = 5;
    int ans1 = 2;
    std::vector<int> nums2 = {3,1,3,4,3};
    int k2 = 6;
    int ans2 = 1;
    std::vector<int> nums3 = {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};
    int k3 = 2;
    int ans3 = 2;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.maxOperations(nums1, k1) == ans1);
    assert(solution.maxOperations(nums2, k2) == ans2);
    assert(solution.maxOperations(nums3, k3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}