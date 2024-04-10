#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int num2 = INT_MAX;
        int num3 = INT_MAX;

        for (auto& num : nums) {
            if (num <= num2) {
                num2 = num;
            } else if (num <= num3) {
                num3 = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

/*

*/

int main() {
    Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    std::vector<int> nums1 = {1,2,3,4,5};
    assert(solution.increasingTriplet(nums1) == true);
    std::vector<int> nums2 = {5,4,3,2,1};
    assert(solution.increasingTriplet(nums2) == false);
    std::vector<int> nums3 = {2,1,5,0,4,6};
    assert(solution.increasingTriplet(nums3) == true);
    std::vector<int> nums4 = {1,2,1,7,5,6};
    assert(solution.increasingTriplet(nums4) == true);
    std::vector<int> nums5 = {2,4,-2,-3};
    assert(solution.increasingTriplet(nums5) == false);
    std::vector<int> nums6 = {1,5,0,4,1,3};
    assert(solution.increasingTriplet(nums6) == true);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}