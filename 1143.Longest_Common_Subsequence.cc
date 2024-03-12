#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int n = text1.size();
        int m = text2.size();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = ++dp[i][j];
                } else {
                    dp[i+1][j+1] = std::max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[n][m];
    }
};
/*
        a   b   c   d   e
    0   0   0   0   0   0
a   0   1   1   1   1   1
c   0   1   1   2   2   2
e   0   1   1   2   2   3

Can be optimized further, only need to keep track of 1 row at a time
*/

int main() {
    Solution solution;

    std::string text1 = "abcde";
    std::string text2 = "ace";
    int ans1 = 3;
    assert(solution.longestCommonSubsequence(text1, text2) == ans1);

    std::string text3 = "abc";
    std::string text4 = "abc";
    int ans2 = 3;
    assert(solution.longestCommonSubsequence(text3, text4) == ans2);

    std::string text5 = "abc";
    std::string text6 = "def";
    int ans3 = 0;
    assert(solution.longestCommonSubsequence(text5, text6) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}