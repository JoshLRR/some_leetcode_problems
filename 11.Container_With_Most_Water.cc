#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = INT_MIN;
        int n = height.size();
        int left = 0;
        int right = n-1;

        while (left < right) {
            int currentArea = std::min(height[left], height[right]) * (right - left);
            maxArea = std::max(maxArea, currentArea);

            if (height[left] > height[right]) {
                --right;
            } else if (height[right] > height[left]) {
                ++left;
            } else {        // Arbitrarily move the left?
                ++left;
            }
        }

        return maxArea;
    }
};

/*
    Two pointer
    Start left at 0, start right at the end
    Keep track of maxArea
    Calculate current area as min(nums[left],nums[right]) * right-left -- compare to maxArea
    Keep the taller one, increment/decrement the smaller of nums[left] and nums[right]
*/

int main() {
    Solution solution;
    std::vector<int> heights1 = {1,8,6,2,5,4,8,3,7};
    int ans1 = 49;
    assert(solution.maxArea(heights1) == ans1);

    std::vector<int> heights2 = {1,1};
    int ans2 = 1;
    assert(solution.maxArea(heights2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}