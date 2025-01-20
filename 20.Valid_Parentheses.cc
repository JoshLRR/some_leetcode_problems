#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() == 1) return false;

        std::stack<char> stack;

        for (auto& paren : s) {
            if (paren == '(' || paren == '[' || paren == '{') {
                stack.push(paren);
            } else if (!stack.empty() && paren == ')' && stack.top() == '(') {
                stack.pop();
            } else if (!stack.empty() && paren == ']' && stack.top() == '[') {
                stack.pop();    
            } else if (!stack.empty() && paren == '}' && stack.top() == '{') {
                stack.pop();
            } else {
                return false;
            }
        }

        return stack.empty();
    }
};

/*

*/

int main() {
    Solution solution;
    std::string s1 = "()";
    bool ans1 = true;

    std::string s2 = "()[]{}";
    bool ans2 = true;

    std::string s3 = "(]";
    bool ans3 = false;

    std::string s4 = "([])";
    bool ans4 = true;

    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.isValid(s1); 
    bool test2 = solution.isValid(s2); 
    bool test3 = solution.isValid(s3); 
    bool test4 = solution.isValid(s4); 
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