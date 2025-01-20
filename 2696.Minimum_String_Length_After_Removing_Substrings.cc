#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <stack>

class Solution {
public:
    int minLength(std::string s) {
        std::stack<char> charStack;

        for (int idx = 0; idx < s.length(); ++idx) {
            char curChar = s[idx];

            if (charStack.empty()) {
                charStack.push(curChar);
                continue;
            }

            if (curChar == 'B' && charStack.top() == 'A') charStack.pop();
            else if (curChar == 'D' && charStack.top() == 'C') charStack.pop();
            else charStack.push(curChar);
        }

        return charStack.size();
    }
};

/*

*/

int main() {
    Solution solution;

    std::string s1 = "ABFCACDB";
    int ans1 = 2;

    std::string s2 = "ACBBD";
    int ans2 = 5;

    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.minLength(s1);
    int test2 = solution.minLength(s2);
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