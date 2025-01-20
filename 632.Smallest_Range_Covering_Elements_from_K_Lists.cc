#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        int rangeMin = INT_MAX;
        int rangeMax = INT_MIN;

        for (auto& list : nums) {
            
        }
        return {};
    }
};
/*

*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> nums1 = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    std::vector ans1 = {20,24};
    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}