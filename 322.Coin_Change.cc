#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> coinCounts(amount+1, amount+1);
        coinCounts[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for(auto& coin : coins) {
                if (i - coin >= 0) coinCounts[i] = std::min(coinCounts[i], 1 + coinCounts[i - coin]);
            }
        }

        return (coinCounts[amount] != amount+1) ? coinCounts[amount] : -1;
    }
};

/*
    Use dp to keep track of how many coins are required for each amount up to the target amount
    Initialize a dp table of size (amount + 1) and initialize all values to amount+1
    For each num (i) from 0 - amount, check each coin in coins. Use a greedy approach
        if i - coin >= 0, that means that coin can be used
            Then, we set dp[i] to the min of dp[i] or 1 + dp[i - coin]. This lets us use previous values
    At the end, if coinCounts[amount] is still amount+1, then we know we never found a valid coin combination and can return -1. Otherwise return the value stored at coinCoutns[amount]
*/

int main() {
    Solution solution;
    std::vector<int> coins1 = {1,2,5};
    int amount1 = 11;
    int ans1 = 3;
    assert(solution.coinChange(coins1, amount1) == ans1);

    std::vector<int> coins2 = {2};
    int amount2 = 3;
    int ans2 = -1;
    assert(solution.coinChange(coins2, amount2) == ans2);

    std::vector<int> coins3 = {1};
    int amount3 = 0;
    int ans3 = 0;
    assert(solution.coinChange(coins3, amount3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}