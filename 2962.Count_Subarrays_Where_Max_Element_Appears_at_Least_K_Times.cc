#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        int n = nums.size();
        int maxValCount = 0;
        int left = 0;
        long long ans = 0;

        for (int right = 0; right < n; ++right) {
            // maxValCount += nums[right] == maxVal;
            if (nums[right] == maxVal) {
                ++maxValCount;
            }
            while (maxValCount >= k) {
                // maxValCount -= nums[left++] == maxVal;
                if (nums[left++] == maxVal) {
                    --maxValCount;
                }
            }
            ans += left;
        }

        return ans;
    }
};

/*
    Sliding Window --
    This solution is big brain because of the ans += left.
    For every right position, we know that there are 'left' positions where the subarray could start and still include k number of maxValCount
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,3,2,3,3};
    int k1 = 2;
    int ans1 = 6;
    assert(solution.countSubarrays(nums1, k1) == ans1);

    std::vector<int> nums2 = {1,4,2,1};
    int k2 = 3;
    int ans2 = 0;
    assert(solution.countSubarrays(nums2, k2) == ans2);

    std::vector<int> nums3 = {61,23,38,23,56,40,82,56,82,82,82,70,8,69,8,7,19,14,58,42,82,10,82,78,15,82};
    int k3 = 2;
    int ans3 = 224;
    assert(solution.countSubarrays(nums3, k3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}