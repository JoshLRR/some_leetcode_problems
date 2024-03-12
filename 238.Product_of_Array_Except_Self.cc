#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 0);
        int cumSum = 1;

        for (int i = 0; i < n; ++i) {
            ans[i] = cumSum;
            cumSum *= nums[i];

            for(auto& val : ans) {
                std::cout << val << " ";
            }
            std::cout << "cumSum: " << cumSum << "\n";
        }
        cumSum = 1;
        for (int i = n-1; i >= 0; --i) {
            ans[i] *= cumSum;
            cumSum *= nums[i];

            for(auto& val : ans) {
                std::cout << val << " ";
            }
            std::cout << "cumSum: " << cumSum << "\n";
        }

        return ans;
    }
};
/*
    {1,2,3,4} --> {24,12,8,6}
    Forward loop, carry forward product of all values to the left of nums[i]
    Backwards loop, carry back product of all values to the right of nums[i]

    1 0 0 0 
    1 1 0 0 
    1 1 2 0 
    1 1 2 6 
    1 1 2 6 
    1 1 8 6 
    1 12 8 6 
    24 12 8 6 
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,2,3,4};
    std::vector<int> ans1 = {24,12,8,6};
    assert(solution.productExceptSelf(nums1) == ans1);

    std::vector<int> nums2 = {-1,1,0,-3,3};
    std::vector<int> ans2 = {0,0,9,0,0};
    assert(solution.productExceptSelf(nums2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}