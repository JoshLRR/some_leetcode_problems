#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        for (; j < nums.size(); ++j) {
            nums[j] = 0;
        }
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {0,1,0,3,12};
    std::vector<int> ans1 = {1,3,12,0,0};
    std::vector<int> nums2 = {0};
    std::vector<int> ans2 = {0};
    auto t0 = std::chrono::high_resolution_clock::now();
    solution.moveZeroes(nums1);
    solution.moveZeroes(nums2);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    assert(nums1 == ans1);
    assert(nums2 == ans2);

    // std::cout << "\033[32mAll tests passed in \033[0m" << elapsed << "\033[32m milliseconds!\033[0m\n";
    double time = elapsed.count() / 1e6;

    // std::cout << "\033[32mAll tests passed!\033[0m";
    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}