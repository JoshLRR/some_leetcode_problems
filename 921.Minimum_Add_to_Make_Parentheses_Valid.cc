#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <stack>

class Solution {
public:
    // int minAddToMakeValid(std::string s) {
    //     std::stack<char> openStack;
    //     int ans = 0;

    //     for (int idx = 0; idx < s.size(); ++idx) {
    //         if (s[idx] == '(') {
    //             openStack.push(s[idx]);
    //         } else {
    //             if (openStack.empty()) {
    //                 ++ans;
    //             } else {
    //                 openStack.pop();
    //             }
    //         }
    //     }

    //     return ans + openStack.size();
    // }
    int minAddToMakeValid(std::string s) {
        int opens = 0;
        int closes = 0;

        for (int idx = 0; idx < s.size(); ++idx) {
            if (s[idx] == '(') {
                ++opens;
            } else {
                opens > 0 ? --opens : ++closes;
            }
        }

        return opens + closes;
    }
};

/*

*/

int main() {
    Solution solution;
    std::string s1 = "())";
    int ans1 = 1;

    std::string s2 = "(((";
    int ans2 = 3;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.minAddToMakeValid(s1);
    int test2 = solution.minAddToMakeValid(s2);
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