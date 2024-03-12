#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> encountered;

        for (int i = 0; i < nums.size(); ++i) {
            if (encountered.find(target - nums[i]) != encountered.end()) {
                return {encountered[target - nums[i]], i};
            } else {
                encountered[nums[i]] = i;
            }
        }

        return {};
    }
};

/*
    O(n) time complexity at tradeoff cost of increased memory complexity
    Lower time complexity can be achieved by sacrificing and increasing time complexity to O(n^2)
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {2,7,11,15};
    int target = 9;
    std::vector<int> ans1 = {0,1};
    assert(solution.twoSum(nums1, target) == ans1);

    std::vector<int> nums2 = {3,2,4};
    int target2 = 6;
    std::vector<int> ans2 = {1,2};
    assert(solution.twoSum(nums2, target2) == ans2);
    
    std::vector<int> nums3 = {3,3};
    int target3 = 6;
    std::vector<int> ans3 = {0,1};
    assert(solution.twoSum(nums3, target3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}