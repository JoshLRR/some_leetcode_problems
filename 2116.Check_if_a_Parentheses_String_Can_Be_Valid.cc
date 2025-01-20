#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    bool canBeValid(std::string s, std::string locked) {
        int n = s.size();
        if (n == 1) {
            return false;
        }

        std::stack<char> parenStack;
        bool* needsMod = new bool[n];
        memset(needsMod, false, n);
        // bool needsModification = false;

        for (int idx = 0; idx < n; ++idx) {
            char paren = s[idx];

            if (paren == '(' || paren == '{' || paren == '[') {
                parenStack.push(paren);
            } else if (!parenStack.empty() && paren == ')' && parenStack.top() == '(') {
                parenStack.pop();
            } else if (!parenStack.empty() && paren == '}' && parenStack.top() == '{') {
                parenStack.pop();
            } else if (!parenStack.empty() && paren == ']' && parenStack.top() == '[') {
                parenStack.pop();
            } else {
                needsMod[idx] = true;
            }
        }

        // std::cout << "needsMod contents\n";
        for (int idx = 0; idx < n; ++idx) {
            // std::cout << idx << " : " << needsMod[idx] << "\n";
            if (needsMod[idx] && locked[idx] == '0') {
                std::cout << "Modifying indexes " << idx << " and " << idx + 1 << "\n";
                needsMod[idx] = false;
                needsMod[idx + 1] = false;
            } 
        }

        bool hooray = true;
        for (int idx = 0; idx < n; ++idx) {
            std::cout << idx << " : " << needsMod[idx] << "\n";
            if (needsMod[idx] == true) {
                hooray = false;
            }
        }
        
        free(needsMod);
        return hooray; // Change this
    }
};

/*
    First determine if s is valid without modification
    Then figure out which characters need to be modified to make it valid
    Checking the same index in 'locked', see if it's possible to make the necessary modification

    Valid:
    ()
    AB where A and B are both valid parentheses ()
    (A) where A is a valid parantheses string
*/

int main() {
    Solution solution;

    std::string s1 = "))()))";
    std::string locked1 = "010100";
    bool ans1 = true;

    std::string s2 = "()()";
    std::string locked2 = "0000";
    bool ans2 = true;

    std::string s3 = ")";
    std::string locked3 = "0";
    bool ans3 = false;

    std::string s4 = "())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(";
    std::string locked4 = "100011110110011011010111100111011101111110000101001101001111";
    bool ans4 = false;

    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.canBeValid(s1, locked1);
    bool test2 = solution.canBeValid(s2, locked2);
    bool test3 = solution.canBeValid(s3, locked3);
    bool test4 = solution.canBeValid(s4, locked4);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);
    assert(test4 == ans4);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}