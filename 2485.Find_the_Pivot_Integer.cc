#include <iostream>
#include <cassert>
#include <vector>
class Solution {
public:
    int pivotInteger(int n) {
        std::vector<int> dp(n+2, 0);
        for (int i = n; i > 0; --i) {
            dp[i] = i + dp[i + 1];
        }

        for (int i = 1; i <= n; ++i) {
            int currSum = i * (i+1) / 2;
            if (currSum == dp[i]) return i;
        }

        // for(auto& num : dp) {
        //     std::cout << num << " ";
        // }

        // std::cout << "\n";
        return -1;
    }
};

/*
    Sum from 1 -> pivot should be the same as pivot -> n
    Sum formula = n * (n+1) / 2
*/

int main() {
    Solution solution;
    int n1 = 8;
    int ans1 = 6;
    assert(solution.pivotInteger(n1) == ans1);

    int n2 = 1;
    int ans2 = 1;
    assert(solution.pivotInteger(n2) == ans2);

    int n3 = 4;
    int ans3 = -1;
    assert(solution.pivotInteger(n3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}