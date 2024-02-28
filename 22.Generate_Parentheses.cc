#include <iostream>
#include <cassert>

class Solution {
public:
    std::vector<std::string> ans;
    std::string currentCombo;
    int numOpenParen = 0;
    int numCloseParen = 0;
    void dfs(int n) {
        // Base Case
        if (currentCombo.size() == n * 2) {
            ans.push_back(currentCombo);
            return;
        }
        // Recursive Case
        if (numOpenParen < n) {
            ++numOpenParen;
            currentCombo.push_back('(');
            dfs(n);
            currentCombo.pop_back();
            --numOpenParen;
        }

        if (numCloseParen < numOpenParen) {
            ++numCloseParen;
            currentCombo.push_back(')');
            dfs(n);
            currentCombo.pop_back();
            --numCloseParen;
        }
        
    }

    std::vector<std::string> generateParenthesis(int n) {
        dfs(n);

        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> expected1 = {"((()))","(()())","(())()","()(())","()()()"};
    assert(solution.generateParenthesis(3) == expected1);

    std::cout << "All tests passed!";
    return 0;
}