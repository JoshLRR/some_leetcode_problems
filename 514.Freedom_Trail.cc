#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findRotateSteps(std::string ring, std::string key) {
        int n = ring.size();
        int m = key.size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, INT_MAX));
        
        // Map to store the positions of each character in 'ring'
        std::unordered_map<char, std::vector<int>> charPositions;
        for (int i = 0; i < n; ++i) {
            charPositions[ring[i]].push_back(i);
        }
        
        // Initialize dp for the first character in the key
        for (int pos : charPositions[key[0]]) {
            dp[0][pos] = std::min(pos, n - pos) + 1; // Include pressing the button
        }

        // Fill the dp table
        for (int i = 1; i < m; ++i) {
            for (int j : charPositions[key[i]]) {
                for (int k : charPositions[key[i-1]]) {
                    int diff = std::abs(j - k);
                    int step = std::min(diff, n - diff) + 1; // +1 for pressing the button
                    dp[i][j] = std::min(dp[i][j], dp[i-1][k] + step);
                }
            }
        }

        // Find the minimum steps required to spell the last character in 'key'
        int min_steps = INT_MAX;
        for (int i : charPositions[key[m-1]]) {
            min_steps = std::min(min_steps, dp[m-1][i]);
        }

        return min_steps;
    }
};

/*
Brute Force --
    1. Check if current ring selection is on the next desired character in key 
    2. If not, count steps to reach next character by going clockwise or anti-clockwise -- take the shorter path
    3. Reach the desired character and press the button to select the character -- this counts as a step too
    4. Repeat until no chars remain in key

Using DFS for Brute Force -- 
    1. Base Case -- Current character is the desired character
    2. Recursive Case -- Pass the characters to the left and right to the next recursive call

Dynamic Programming --


*/

int main() {
    Solution solution;
    std::string ring1 = "godding";
    std::string key1 = "gd";
    int ans1 = 4;
    std::string ring2 = "godding";
    std::string key2 = "godding";
    int ans2 = 13;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.findRotateSteps(ring1,key1) == ans1);
    assert(solution.findRotateSteps(ring2,key2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}