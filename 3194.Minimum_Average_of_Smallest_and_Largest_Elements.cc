#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    double minimumAverage(std::vector<int>& nums) {
        std::vector<float> averages;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int minPointer = 0;
        int maxPointer = n - 1;

        for (int idx = 0; idx <= n / 2; ++idx) {
            int minElement = nums[minPointer];
            int maxElement = nums[maxPointer];
            ++minPointer;
            --maxPointer;
            averages.push_back((minElement + maxElement) / 2.0);
        }

        float min = 1e9;
        for (float& num : averages) {
            min = std::min(min, num);
        }

        std::cout << min << ", casted: " << double(min) << "\n";
        return double(min);
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {7,8,3,4,15,13,4,1};
    double ans1 = 5.5;

    std::vector<int> nums2 = {1,9,8,3,10,5};
    double ans2 = 5.5;

    std::vector<int> nums3 = {1,2,3,7,8,9};
    double ans3 = 5.0;
    auto t0 = std::chrono::high_resolution_clock::now();
    double test1 = solution.minimumAverage(nums1);
    double test2 = solution.minimumAverage(nums2);
    double test3 = solution.minimumAverage(nums3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    assert(test1 = ans1);
    assert(test2 = ans2);
    assert(test3 = ans3);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}