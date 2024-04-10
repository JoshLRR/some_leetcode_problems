#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    // long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
    //     int left = 0;
    //     int currMinValue = INT_MAX; // Min Value needs to be equal to minK
    //     int currMaxValue = INT_MIN; // Max value needs to be equal to maxK
    //     int ans = 0;

    //     for (int right = 0; right < nums.size(); ++right) {
    //         if (nums[right] < currMinValue) {
    //             // currMinValue = nums[right];
    //             currMinValue = right;
    //         }
    //         if (nums[right] > currMaxValue) {
    //             // currMaxValue = nums[right];
    //             currMaxValue = right;
    //         }

    //         ans += std::max(0, std::min(currMinValue, currMaxValue) - left + 1);
    //     }

    //     std::cout << ans << "\n";
    //     return ans;
    // }
    long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
        long ans = 0;
        int start = -1;
        int lastMinIndex = -1;
        int lastMaxIndex = -1;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                start = i;
            }
            if (nums[i] == minK) {
                lastMinIndex = i;
            }
            if (nums[i] == maxK) {
                lastMaxIndex = i;
            }
            ans += std::max(0, std::min(lastMinIndex, lastMaxIndex) - start);
        }
        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,3,5,2,7,5};
    int mink1 = 1;
    int maxk1 = 5;
    int ans1 = 2;
    assert(solution.countSubarrays(nums1, mink1, maxk1) == ans1);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}