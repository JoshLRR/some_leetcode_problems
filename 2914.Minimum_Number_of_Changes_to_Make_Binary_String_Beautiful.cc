#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int minChanges(std::string s) {
        int totalChanges = 0;

        for (int idx = 0; idx < s.size(); idx += 2) {
            if (s[idx] != s[idx + 1]) {
                ++totalChanges;
            }
        }

        return totalChanges;
    }
};
/*
    Make blocks of size 2
*/

int main() {
    Solution solution;

    std::string s1 = "1001";
    int ans1 = 2;

    std::string s2 = "10";
    int ans2 = 1;

    std::string s3 = "0000";
    int ans3 = 0;

    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.minChanges(s1);
    int test2 = solution.minChanges(s2);
    int test3 = solution.minChanges(s3);
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