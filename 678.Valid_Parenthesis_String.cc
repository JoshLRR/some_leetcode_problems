#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <stack>

class Solution {
public:
    bool checkValidString(std::string s) { 
        if (s.size() == 1 && s[0] != '*') return false;
        std::stack<int> openParenStack;
        std::stack<int> starStack;

        for (int idx = 0; idx < s.size(); ++idx) {
            char curr = s[idx];

            if (curr == '(') {
                openParenStack.push(idx);

            } else if (curr == ')') {
                if (!openParenStack.empty()) {
                    openParenStack.pop();

                } else if (openParenStack.empty() && !starStack.empty()) {
                    starStack.pop();

                } else {
                    return false;
                }
            } else {
                starStack.push(idx);
            }
        }

        while (!openParenStack.empty() && !starStack.empty()) {
            if (openParenStack.top() > starStack.top()) return false; 
            openParenStack.pop();
            starStack.pop();
        }

        if (!openParenStack.empty()) return false;

        return true;
    }
};

/*
    Two stacks -- one stack for open paren, one stack for *
*/

int main() {
    Solution solution;

    std::string s1 = "()";
    bool ans1 = true;
    std::string s2 = "(*)";
    bool ans2 = true;
    std::string s3 = "(*))";
    bool ans3 = true;
    std::string s4 = "****((((";
    bool ans4 = false;
    std::string s5 = "(";
    bool ans5 = false;
    std::string s6 = "*";
    bool ans6 = true;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.checkValidString(s1) == ans1);
    assert(solution.checkValidString(s2) == ans2);
    assert(solution.checkValidString(s3) == ans3);
    assert(solution.checkValidString(s4) == ans4);
    assert(solution.checkValidString(s5) == ans5);
    assert(solution.checkValidString(s6) == ans6);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!"
              << "\033[0m";

    return 0;
}