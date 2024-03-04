#include <iostream>
#include <cassert>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        std::vector<int> ans(n, 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (std::abs(nums[left]) > std::abs(nums[right])) {
                ans[i] = nums[left] * nums[left];
                ++left;
            } else if (std::abs(nums[right]) > std::abs(nums[left])) {
                ans[i] = nums[right] * nums[right];
                --right;
            } else { // if abs(num) are the same, arbitrarily use the right
                ans[i] = nums[right] * nums[right];
                --right;
            }
        }

        for(auto& val: ans) {
            std::cout << val << " ";
        }
        std::cout << "\n";

        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> input1 = {-4,-1,0,3,10};
    std::vector<int> ans1 = {0,1,9,16,100};
    std::vector<int> input2 = {-7,-3,2,3,11};
    std::vector<int> ans2 = {4,9,9,49,121};

    assert(solution.sortedSquares(input1) == ans1);
    assert(solution.sortedSquares(input2) == ans2);

    std::cout << "All tests passed!";
    return 0;
}