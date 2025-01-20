#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int largestCombo = INT_MIN;
        int setBitMap[24];
        memset(setBitMap, 0, sizeof(setBitMap));

        for (auto& num : candidates) {
            for (int idx = 0; idx < 24; ++idx) {
                if ((num & 1) == 1) ++setBitMap[idx];
                num >>= 1;
            }
        }

        for (auto& num : setBitMap) {
            largestCombo = std::max(largestCombo, num);
        }

        return largestCombo;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> candidates1 = {16,17,71,62,12,24,14};
    int ans1 = 4;

    std::vector<int> candidates2 = {8,8};
    int ans2 = 2;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.largestCombination(candidates1);
    int test2 = solution.largestCombination(candidates2);
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