#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int prefixCount(std::vector<std::string>& words, std::string pref) {
        int count = 0;

        for (auto& word : words) {
            if (word.find(pref) != std::string::npos && word.find(pref) == 0) {
                ++count;
            }
        }

        return count;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<std::string> words1 = {"pay", "attention", "practice", "attend"};
    std::string pref1 = "at";
    int ans1 = 2;

    std::vector<std::string> words2 = {"leetcode","win","loops","success"};
    std::string pref2 = "code";
    int ans2 = 0;

    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.prefixCount(words1, pref1);
    int test2 = solution.prefixCount(words2, pref2);
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