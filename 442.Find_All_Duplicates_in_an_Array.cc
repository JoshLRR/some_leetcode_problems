#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) {
        std::vector<int> ans;

        for (auto& num : nums) {
            int currIdx = std::abs(num) - 1;

            if (nums[currIdx] < 0) {
                ans.push_back(std::abs(num));
            } else {
                nums[currIdx] = -1 * nums[currIdx];
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

Find all nums that appear more than once in nums in linear time and constant space

Can take advantage of the fact that nums are sorted from 1 - n
For every num we encountered, we flip the index of that num to a negative, when we encounter a negative we know that that index has been seen as a num

For example,
nums1:

We see 2, we then flip nums[2] to a negative. If we run into 2 again, when we check nums[2], we'll find a negative and know that it's a duplicate

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {4,3,2,7,8,2,3,1};
    std::vector<int> ans1 = {2,3};
    assert(solution.findDuplicates(nums1) == ans1);

    std::vector<int> nums2 = {1,1,2};
    std::vector<int> ans2 = {1};
    assert(solution.findDuplicates(nums2) == ans2);

    std::vector<int> nums3 = {1};
    std::vector<int> ans3 = {};
    assert(solution.findDuplicates(nums3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}