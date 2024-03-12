#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>
#include <bitset>

class Solution {
public:
    // int missingNumber(std::vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = n * (n + 1) / 2;
    //     int actualSum = std::accumulate(nums.begin(), nums.end(), 0);

    //     return sum - actualSum;
    // }
    int missingNumber(std::vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};

/*
    Approach 1: Use series sum formula
    Approach 2: XOR
        XOR the index and value for each num in nums[i]
        Since i = nums[i] for the values that are included, the one that will be left is the nonincluded
    Both of these have the same time and space complexity
    Time -- O(n) since we have to either sum all values together or iterate through the whole list
    Space -- O(1) Don't need additional space to solve
*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {3, 0, 1};
    int ans1 = 2;
    assert(solution.missingNumber(nums1) == ans1);

    std::vector<int> nums2 = {0,1};
    int ans2 = 2;
    assert(solution.missingNumber(nums2) == ans2);

    std::vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    int ans3 = 8;
    assert(solution.missingNumber(nums3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}