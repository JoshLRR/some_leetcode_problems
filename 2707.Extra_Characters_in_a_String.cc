#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int dp[51] = {}; // s.length capped at 50, have one extra at the end to easily handle i + 1
        int n = s.size();

        for (int idx = n - 1; idx >= 0; --idx) {
            dp[idx] = 1 + dp[idx + 1];

            for (auto& word : dictionary) {
                if (idx + word.size() <= n && s.compare(idx, word.size(), word) == 0) {
                    dp[idx] = std::min(dp[idx], dp[idx + word.size()]);
                }
            }
        }

        return dp[0];
    }
};

/*
    -- Bottom up --

    Iterate backwards through the string
*/

int main() {
    Solution solution;
    std::string s1 = "leetscode";
    std::vector<std::string> dict1 = {"leet", "code", "leetcode"};
    int ans1 = 1;

    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.minExtraChar(s1, dict1);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    // assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}