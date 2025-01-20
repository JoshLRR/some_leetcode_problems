#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    long long countLess(std::vector<int>& nums, int val) {
        long long fairPairCount = 0;

        for (int left = 0, right = nums.size() - 1; left < right; ++left) {
            while (left < right && nums[left] + nums[right] > val) {
                --right;
            }
            fairPairCount += right - left;
        }

        return fairPairCount;
    }

    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        return countLess(nums, upper) - countLess(nums, lower - 1);
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {0,1,7,4,4,5};
    int lower1 = 3;
    int upper1 = 6;
    long long ans1 = 6;

    std::vector<int> nums2 = {1,7,9,2,5};
    int lower2 = 11;
    int upper2 = 11;
    long long ans2 = 1;

    std::vector<int> nums3 = {0,0,0,0,0,0};
    int lower3 = 0;
    int upper3 = 0;
    long long ans3 = 15;

    auto t0 = std::chrono::high_resolution_clock::now();
    long long test1 = solution.countFairPairs(nums1, lower1, upper1);
    long long test2 = solution.countFairPairs(nums2, lower2, upper2);
    long long test3 = solution.countFairPairs(nums3, lower3, upper3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}