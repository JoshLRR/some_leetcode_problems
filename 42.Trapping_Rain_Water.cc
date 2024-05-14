#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeftHeight = height[left];
        int maxRightHeight = height[right];
        int trappedWater = 0;

        while (left < right) {
            if (maxLeftHeight < maxRightHeight) {
                ++left;
                maxLeftHeight = std::max(maxLeftHeight, height[left]);
                trappedWater += maxLeftHeight - height[left];
            } else {
                --right;
                maxRightHeight = std::max(maxRightHeight, height[right]);
                trappedWater += maxRightHeight - height[right];
            }
        }

        return trappedWater;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> heights1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans1 = 6;
    std::vector<int> heights2 = {4,2,0,3,2,5};
    int ans2 = 9;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.trap(heights1) == ans1);
    assert(solution.trap(heights2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}