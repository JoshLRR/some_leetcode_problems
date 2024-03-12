#include <iostream>
#include <cassert>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int seenOnce = 0;
        int seenTwice = 0;

        for (auto& num : nums) {
            seenOnce ^= num & ~seenTwice;
            seenTwice ^= num & ~seenOnce;
        }

        return seenOnce;
    }
};

/*
    10, 10, 11, 10
    seenOnce: 0 ^ 10 & ~10
    seenTwice: 10 & 10 --> 10
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {2,2,3,2};
    int ans1 = 3;
    assert(solution.singleNumber(nums1) == ans1);

    std::vector<int> nums2 = {0,1,0,1,0,1,99};
    int ans2 = 99;
    assert(solution.singleNumber(nums2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}