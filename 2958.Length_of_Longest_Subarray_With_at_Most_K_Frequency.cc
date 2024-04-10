#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        std::unordered_map<int, int> freqMap;
        int n = nums.size();
        int maxSubLength = 0;

        while (right < n) {
            ++freqMap[nums[right]];
            while (freqMap[nums[right]] > k) {
                --freqMap[nums[left]];
                ++left;
            }
           
            maxSubLength = std::max(maxSubLength, right - left + 1);
            ++right;
        }
        // std::cout << maxSubLength << "\n";
        return maxSubLength;
    }
};
/*
    Sliding window + frequency map
    Keep frequency map of each number, expand window while no frequency is above k
    If a character is found and has a frequency above k, shrink window until it's no longer above k
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,2,3,1,2,3,1,2};
    int k1 = 2;
    int ans1 = 6;
    assert(solution.maxSubarrayLength(nums1, k1) == ans1);

    std::vector<int> nums2 = {1,2,1,2,1,2,1,2};
    int k2 = 1;
    int ans2 = 2;
    assert(solution.maxSubarrayLength(nums2, k2) == ans2);

    std::vector<int> nums3 = {5,5,5,5,5,5,5};
    int k3 = 4;
    int ans3 = 4;
    assert(solution.maxSubarrayLength(nums3, k3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}