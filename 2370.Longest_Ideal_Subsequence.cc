#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <algorithm> 
// class Solution {
// public:
//     int longestIdealString(std::string s, int k) {
//         std::vector<int> dp(s.size() + 1);
//         dp[0] = 0;

//         for (int i = 0; i < s.size(); ++i) {
//             if ((s[i] - 'a') - (s[i - 1] - 'a') <= k) {
//                 dp[i + 1] = dp[i] + 1;
//             } else {
//                 dp[i + 1] = dp[i];
//             }
//         }

//         for (auto& num : dp) {
//             std::cout << num << ", ";
//         }
//         std::cout << "\n";
//         std::cout << dp[s.size()] << "\n";
//         return dp[s.size()];
//     }
// };

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int longestIdealString(std::string s, int k) {
        std::array<int, 26> dp;
        dp.fill(0);
        int maxLen = 0;

        for (char c : s) {
            int currentMax = 0;
            for (int d = std::max(int('a'), int(c - k)); d <= std::min(int('z'), int(c + k)); ++d) {
                currentMax = std::max(currentMax, dp[d - 'a']);
            }
            dp[c - 'a'] = currentMax + 1;
            maxLen = std::max(maxLen, dp[c - 'a']);
        }

        return maxLen;
    }
};


/*
    Dynamic Programming -- 
    - Create a vector of length s.size() + 1
    - Iterate through s, if s[i + 1] - s[i] is less than or equal to k, dp[i] = dp[i - 1]
*/

int main() {
    Solution solution;

    std::string s1 = "acfgbd";
    int k1 = 2;
    int ans1 = 4;
    std::string s2 = "abcd";
    int k2 = 3;
    int ans2 = 4;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.longestIdealString(s1, k1) == ans1);
    assert(solution.longestIdealString(s2, k2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}