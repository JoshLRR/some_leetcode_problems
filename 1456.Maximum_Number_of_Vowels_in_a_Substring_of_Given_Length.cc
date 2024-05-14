#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
class Solution {
public:
    int maxVowels(std::string s, int k) {
        int left = 0;
        int right = k - 1;
        int ans = 0;
        int count = 0;

        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < k; ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                ++ans;
                ++count;
            }
        }

        while (right < s.size()) {
            if (vowels.find(s[left]) != vowels.end()) {
                --count;
            }
            ++left;

            ++right;
            if (vowels.find(s[right]) != vowels.end()) {
                ++count;
            }

            ans = std::max(ans, count);
        }

        // std::cout << ans << "\n";
        return ans;
    }
};
/*

*/

int main() {
    Solution solution;

    std::string s1 = "abciiidef";
    int k1 = 3;
    int ans1 = 3;
    std::string s2 = "aeiou";
    int k2 = 2;
    int ans2 = 2;
    std::string s3 = "leetcode";
    int k3 = 3;
    int ans3 = 2;
    std::string s4 = "ibpbhixfiouhdljnjfflpapptrxgcomvnb";
    int k4 = 33;
    int ans4 = 7;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.maxVowels(s1, k1) == ans1);
    assert(solution.maxVowels(s2, k2) == ans2);
    assert(solution.maxVowels(s3, k3) == ans3);
    assert(solution.maxVowels(s4, k4) == ans4);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}