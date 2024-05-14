#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <numeric>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0);

        int leftSum = 0;
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            rightSum -= nums[idx];

            if (leftSum == rightSum) {
                return idx;
            }

            leftSum += nums[idx];
        }
        
        return -1;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {1,7,3,6,5,6};
    int ans1 = 3;
    std::vector<int> nums2 = {1,2,3};
    int ans2 = -1;
    std::vector<int> nums3 = {2,1,-1};
    int ans3 = 0;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.pivotIndex(nums1) == ans1);
    assert(solution.pivotIndex(nums2) == ans2);
    assert(solution.pivotIndex(nums3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}