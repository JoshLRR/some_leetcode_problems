#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(2, 1);
        dp[0] = 1;
        dp[1] = 2;

        if (n == 1) return dp[0];

        for (int i = 2; i < n; ++i) {
            if (i % 2 == 0) {
                dp[0] = dp[0] + dp[1];
            } 
            if (i % 2 == 1) {
                dp[1] = dp[0] + dp[1];
            }
        }

        return std::max(dp[0], dp[1]);
    }
};

/*
    1 step -- 1 way
    2 steps -- 1 + 1, 2 -- 2 ways
    3 steps -- 1 + 1 + 1, 2 + 1, 1 + 2 -- 3 ways
    4 steps -- 1,1,1,1 ; 2,2 ; 2,1,1; 1,1,2; 1,2,1; -- 5 ways
    Fibonacci sequence
*/

int main() {
    Solution solution;
    int n1 = 2;
    int ans1 = 2;
    assert(solution.climbStairs(n1) == ans1);

    int n2 = 3;
    int ans2 = 3;
    assert(solution.climbStairs(n2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}