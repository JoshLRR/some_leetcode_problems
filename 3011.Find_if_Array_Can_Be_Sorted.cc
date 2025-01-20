#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <bit>

class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
        const uint8_t n = nums.size();
        uint16_t pmax = 0, cmin = 0, cmax = 0;
        uint8_t pcnt = 0;

        for (const uint16_t num : nums) {
            if (const uint8_t ccnt = std::popcount(num); pcnt == ccnt) {
                cmin = std::min(cmin, num);
                cmax = std::max(cmax, num);
            } else if (cmin < pmax) {
                return false;
            } else {
                pmax = cmax;
                cmin = cmax = num;
                pcnt = ccnt;
            }
        }
        return cmin >= pmax;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {8,4,2,30,15};
    bool ans1 = true;

    std::vector<int> nums2 = {1,2,3,4,5};
    bool ans2 = false;

    std::vector<int> nums3 = {3,16,8,4,2};
    bool ans3 = false;

    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.canSortArray(nums1);
    bool test2 = solution.canSortArray(nums2);
    bool test3 = solution.canSortArray(nums3);
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