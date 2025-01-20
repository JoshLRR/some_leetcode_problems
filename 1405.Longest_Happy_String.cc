#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class Solution {
public:
    std::string longestDiverseString(int a, int b, int c) {
        std::priority_queue<std::pair<char, int>> letterCounts;
        letterCounts.push({'a', a});
        letterCounts.push({'b', b});
        letterCounts.push({'c', c});
        std::string ans = "";

        

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;
    int a1 = 1, b1 = 1, c1 = 7;
    std::string ans1 = "ccaccbcc";  // ccbccacc would also be a correct answer

    int a2 = 7, b2 = 1, c2 = 0;
    std::string ans2 = "aabaa";
    auto t0 = std::chrono::high_resolution_clock::now();
    std::string test1 = solution.longestDiverseString(a1,b1,c1);
    std::string test2 = solution.longestDiverseString(a2,b2,c2);
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