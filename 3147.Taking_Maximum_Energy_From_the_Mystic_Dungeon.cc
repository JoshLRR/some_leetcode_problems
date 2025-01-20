#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int maximumEnergy(std::vector<int>& energy, int k) {
        int n = energy.size();
        std::vector<int> dp(n, 0); 

        for (int idx = n - 1; idx >= 0; --idx) {
            dp[idx] = energy[idx] + ((idx + k < n) ? dp[idx + k] : 0);
        }

        int maxTotalEnergy = INT_MIN;
        for (int idx = 0; idx < n; ++idx) {
            maxTotalEnergy = std::max(maxTotalEnergy, dp[idx]);
        }

        return maxTotalEnergy;
    }
};
/*

*/

int main() {
    Solution solution;
    std::vector<int> energy1 = {5,2,-10,-5,1};
    int k1 = 3;
    int ans1 = 3;
    std::vector<int> energy2 = {-2,-3,-1};
    int k2 = 2;
    int ans2 = -1;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.maximumEnergy(energy1, k1) == ans1);
    assert(solution.maximumEnergy(energy2, k2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}