#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        std::vector<int> prefixSums;
        prefixSums.push_back(nums[0]);

        for (int idx = 1; idx < nums.size(); ++idx) {
            prefixSums.push_back(prefixSums[idx - 1] + nums[idx]);
        }

        

        return -1;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {3,1,4,2};
    int p1 = 6;
    int ans1 = 1;
    
    std::vector<int> nums2 = {6,3,5,2};
    int p2 = 9;
    int ans2 = 2;

    std::vector<int> nums3 = {1,2,3};
    int p3 = 3;
    int ans3 = 0;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.minSubarray(nums1, p1);
    int test2 = solution.minSubarray(nums2, p2);
    int test3 = solution.minSubarray(nums3, p3);
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