#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> encountered1;
        std::unordered_set<int> encountered2;

        std::vector<std::vector<int>> ans;
        ans.push_back({});
        ans.push_back({});
        for (auto& num : nums1) {
            encountered1.insert(num);
        }

        for (auto& num : nums2) {
            encountered2.insert(num);
        }

        std::unordered_set<int> inserted;
        for (auto& num : nums2) {
            if (encountered1.find(num) == encountered1.end() && inserted.find(num) == inserted.end()) {
                ans[1].push_back(num);
                inserted.insert(num);
            }
        }
        inserted.clear();
        for (auto& num : nums1) {
            if (encountered2.find(num) == encountered2.end() && inserted.find(num) == inserted.end()) {
                ans[0].push_back(num);
                inserted.insert(num);
            }
        }

        // for(auto& list : ans) {
        //     std::cout << "list: ";
        //     for (auto& num : list) {
        //         std::cout << num << ", ";
        //     }
        //     std::cout << "\n";
        // }
        return ans;

    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4,6};
    std::vector<std::vector<int>> ans1 = {{1,3}, {4,6}};
    std::vector<int> nums3 = {1,2,3,3};
    std::vector<int> nums4 = {1,1,2,2};
    std::vector<std::vector<int>> ans2 = {{3}, {}};
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.findDifference(nums1,nums2) == ans1);
    assert(solution.findDifference(nums3,nums4) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}