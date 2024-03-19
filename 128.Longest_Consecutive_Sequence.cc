#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int maxSequenceCount = 0;
        int currCount = 1;
        std::unordered_set<int> encountered(nums.begin(), nums.end());

        for (auto& num : nums) {
            bool looking = true;
            while (looking) {
                if (encountered.find(num+currCount) != encountered.end()) {
                ++currCount;
                } else {
                    maxSequenceCount = std::max(maxSequenceCount,currCount);
                    looking = false;
                    currCount = 1;
                }
            }
            
        }
        // for (auto& num : nums) {
        //     if (encountered.find(num-1) == encountered.end()) {
        //         int y = num + 1;
        //         while (encountered.find(y) != encountered.end()) {
        //             ++y;
        //         }
        //         maxSequenceCount = std::max(maxSequenceCount, y - num);
        //     }
        // }

        return maxSequenceCount;
    }
};

/*
    100 4   200 1   3   2

    Add all values to a hashmap
    Iterate through all nums
    Check for num-1 in the list, if it does, add to currCount
    Keep track of a max

    TLE for long input
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {100,4,200,1,3,2};
    int ans1 = 4;
    assert(solution.longestConsecutive(nums1) == ans1);

    std::vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    int ans2 = 9;
    assert(solution.longestConsecutive(nums2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}