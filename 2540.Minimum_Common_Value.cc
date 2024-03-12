#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

class Solution {
public:
    // int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
    //     std::unordered_set<int> encountered;

    //     for (auto& num : nums1) {
    //         encountered.insert(num);
    //     }        

    //     for (auto& num : nums2) {
    //         if (encountered.find(num) != encountered.end()) {
    //             return num;
    //         }
    //     }

    //     return -1;
    // }

    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                return nums1[i];
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }

        return -1;
    }
};

/*
    Approach 1: Hash-set
    Iterate through nums1, add all values to the set
    Iterate through nums2, the first number that's also found in the set can be returned
    Time -- 2 total iterations at worst, O(n)
    Space -- O(n) to store nums1 into a set

    Approach 2: Two-pointers
    Iterate through both simultaneously, but only increment the pointer of the array with the smaller value if no match is found
    Time -- O(n) but better than hash-set approach
    Space -- O(1) -- Only need space for pointers
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,4};
    int ans1 = 2;
    assert(solution.getCommon(nums1, nums2) == ans1);

    std::vector<int> nums3 = {1,2,3,6};
    std::vector<int> nums4 = {2,3,4,5};
    int ans2 = 2;
    assert(solution.getCommon(nums3, nums4) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}