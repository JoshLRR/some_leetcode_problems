#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPurchasePrice = INT_MAX;
        int maxProfit = 0;

        for (auto& price : prices) {
            if (price < minPurchasePrice) {
                minPurchasePrice = price;
            }

            int dailyProfit = price - minPurchasePrice ;
            if (dailyProfit > maxProfit) {
                maxProfit = dailyProfit;
            }
        }
        
        return maxProfit;
    }
};

/*
    Iterate through prices, check if daily price is lower than previous min purchase price
    Check the daily profit (daily price - min purchase price), if that day's profit is higher than previous, reassign maxProfit

    return maxProfit
*/

int main() {
    Solution solution;
    std::vector<int> prices1 = {7,1,5,3,6,4};
    int ans1 = 5;
    assert(solution.maxProfit(prices1) == ans1);

    std::vector<int> prices2 = {7,6,4,3,1};
    int ans2 = 0;
    assert(solution.maxProfit(prices2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}