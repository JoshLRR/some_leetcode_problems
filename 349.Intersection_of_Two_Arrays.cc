#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        std::unordered_set<int> encountered(nums1.begin(), nums1.end());

        for (auto& num : nums2) {
            if (encountered.find(num) != encountered.end()) {
                ans.push_back(num);
                encountered.erase(num);
            }
        }

        // for (auto& num : ans) {
        //     std::cout << num << " ";
        // }
        // std::cout << "\n";
        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};
    std::vector<int> ans1 = {2};
    assert(solution.intersection(nums1, nums2) == ans1);

    std::vector<int> nums3 = {4,9,5};
    std::vector<int> nums4 = {9,4,9,8,4};
    std::vector<int> ans2 = {9,4};
    assert(solution.intersection(nums3, nums4) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}