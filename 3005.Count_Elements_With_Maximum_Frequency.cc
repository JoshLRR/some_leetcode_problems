#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::unordered_map<int,int> encountered;
        int maxFreq = 0;
        int ans = 0;
        for (auto& val : nums) {
            if (encountered.find(val) != encountered.end()) {
                ++encountered[val];
                if (encountered[val] > maxFreq) {
                    maxFreq = encountered[val];
                }
            } else {
                encountered[val] = 1;
                if (encountered[val] > maxFreq) {
                    maxFreq = encountered[val];
                }
            }
        }

        for (auto& freq : encountered) {
            if (freq.second == maxFreq) {
                ans += freq.second;
            }
        }
        std::cout << ans << "\n";
        return ans;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {1,2,2,3,1,4};
    int ans1 = 4;
    assert(solution.maxFrequencyElements(nums1) == ans1);

    std::vector<int> nums2 = {1,2,3,4,5};
    int ans2 = 5;
    assert(solution.maxFrequencyElements(nums2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}