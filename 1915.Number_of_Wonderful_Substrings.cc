#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        std::array<long, 1024> count = {};
        count[0] = 1;
        long mask = 0;
        long ans = 0;

        for (auto& ch : word) {
            mask ^= 1 << (ch - 'a');
            ans += count[mask];

            for (int idx = 0; idx < 10; ++idx) {
                ans += count[mask ^ (1 << idx)];
            }
            ++count[mask];
        }

        return ans;
    }
};

/*
Sliding Window won't work

Bit Manipulation -- 

*/

int main() {
    Solution solution;
    std::string word1 = "aba";
    int ans1 = 4;
    std::string word2 = "aabb";
    int ans2 = 9;
    std::string word3 = "he";
    int ans3 = 2;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.wonderfulSubstrings(word1) == ans1);
    assert(solution.wonderfulSubstrings(word2) == ans2);
    assert(solution.wonderfulSubstrings(word3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}