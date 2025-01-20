#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

// Backtracking Approach
// class Solution {
// public:
//     void generateSet(std::vector<std::vector<int>>& subsets, std::vector<int>& currCombo, int start, std::vector<int>& nums) {
//         subsets.push_back(currCombo);

//         for (int idx = start; idx < nums.size(); ++idx) {
//             currCombo.push_back(nums[idx]);
//             generateSet(subsets, currCombo, idx + 1, nums);
//             currCombo.pop_back();
//         }
//     }

//     std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
//         std::vector<std::vector<int>> subsets;
//         std::vector<int> currCombo;
//         generateSet(subsets, currCombo, 0, nums);

//         for (auto& set : subsets) {
//             std::cout << "{";
//             for (auto& num : set) {
//                 std::cout << num << ", ";
//             }
//             std::cout << "}\n";
//         }
//         return subsets;
//     }
// };

// Bit Manipulation Approach
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        int numSubsets = 1 << n; 
        std::vector<std::vector<int>> ans(numSubsets);

        for (int idx = 0; idx < numSubsets; ++idx) {
            for (int jdx = 0; jdx < n; ++jdx) {
                if ((idx >> jdx) & 1) {
                    ans[idx].push_back(nums[jdx]);
                }
            }
        }

        return ans;
    }
};


/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {1,2,3};
    std::vector<std::vector<int>> ans1 = {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}};
    std::vector<int> nums2 = {0};
    std::vector<std::vector<int>> ans2 = {{}, {0}};
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.subsets(nums1) == ans1);
    assert(solution.subsets(nums2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}