#include <iostream>
#include <cassert>
#include <vector>
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector(n, 0));

        for (int i = 0; i < m; ++i) {
            dp[i][n-1] = 1;
        }

        for (int i = 0; i < n; ++i) {
            dp[m-1][i] = 1;
        }

        for (int i = m-2; i >= 0; --i) {
            for (int j = n-2; j >= 0; --j) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }

        for (auto& row : dp) {
            for (auto& cell : row) {
                std::cout << cell << " ";
            }
            std::cout << "\n";
        }
        return dp[0][0];
    }
};

/*
    Bottom-up DP:
    Number of paths for each cell is dependent on the node to the right and beneath
    Initialize the bottom and right-side edge with 1
    Start from the bottom-right and sum the values to the right and underneath
    Return dp[0][0]

    Time complexity -- O(mxn) -> O(n)
    Space complexity -- O(mxn) -- To store the dp table
*/

int main() {
    Solution solution;
    int m1 = 3;
    int n1 = 7;
    int ans1 = 28;
    assert(solution.uniquePaths(m1,n1) == ans1);

    int m2 = 3;
    int n2 = 2;
    int ans2 = 3;
    assert(solution.uniquePaths(m2,n2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}