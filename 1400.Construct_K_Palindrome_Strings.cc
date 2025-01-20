#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    bool canConstruct(std::string s, int k) {
        if (s.size() < k) {
            return false;
        }

        std::unordered_map<char, int> freqMap;
        int oddCount = 0;
        int evenCount = 0;

        for (auto& letter : s) {
            ++freqMap[letter];
        }

        for (auto& keyVal : freqMap) {
            // std::cout << keyVal.first << " : " << keyVal.second << "\n";
            if (keyVal.second % 2 == 1) {
                ++oddCount;
            } else {
                ++evenCount;
            }
        }

        if (oddCount > k) {
            return false;
        } else {
            return true;
        }

        // return freqMap.empty();
    }
};

/*

*/

int main() {
    Solution solution;
    std::string s1 = "annabelle";
    int k1 = 2;
    bool ans1 = true;

    std::string s2 = "leetcode";
    int k2 = 3;
    bool ans2 = false;

    std::string s3 = "true";
    int k3 = 4;
    bool ans3 = true;

    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.canConstruct(s1, k1);
    bool test2 = solution.canConstruct(s2, k2);
    bool test3 = solution.canConstruct(s3, k3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test2 == ans2);


    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}