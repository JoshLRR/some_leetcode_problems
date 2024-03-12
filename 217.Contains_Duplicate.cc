#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> encountered;
        for (auto& num : nums) {
            if (encountered.find(num) != encountered.end()) {
                return true;
            } else {
                encountered.insert(num);
            }
        }

        return false;
    }
};

/*
    Iterate through nums, adding values to an unordered_set for O(1) lookup
    If the current num is found in the set, immediately return true
    If it's not found in the set, add it

    return false if iteration finishes without issue
    O(n) time complexity at worst
    O(n) space complexity

    Can reduce space complexity by increasing time complexity by sorting nums
    sort nums
    if (nums[i] == nums[i]+1), duplicate detected
    O(n logn) time complexity due to sorting
    O(1) space
*/

int main() {
    Solution solution;
    
    std::vector<int> nums1 = {1,2,3,1};
    assert(solution.containsDuplicate(nums1) == true);

    std::vector<int> nums2 = {1,2,3,4};
    assert(solution.containsDuplicate(nums2) == false);

    std::vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};
    assert(solution.containsDuplicate(nums1) == true);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}