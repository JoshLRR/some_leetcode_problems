#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        long long ans = 0;
        std::sort(happiness.begin(), happiness.end());


        for (int i = 0; i < k; ++i) {
            int currHappiness = std::max(happiness.back() - i, 0);
            ans += currHappiness;
            happiness.pop_back();
        }

        // std::cout << ans << "\n";
        return ans;
    }
};

/*
    Loop k times
    Greedily select happiest kids - fuck dem other kids
*/

int main() {
    Solution solution;

    std::vector<int> happiness1 = {1,2,3};
    int k1 = 2;
    int ans1 = 4;
    assert(solution.maximumHappinessSum(happiness1, k1) == ans1);

    std::vector<int> happiness2 = {1,1,1,1};
    int k2 = 2;
    int ans2 = 1;
    assert(solution.maximumHappinessSum(happiness2, k2) == ans2);

    std::vector<int> happiness3 = {2,3,4,5};
    int k3 = 1;
    int ans3 = 5;
    assert(solution.maximumHappinessSum(happiness3, k3) == ans3);

    std::vector<int> happiness4 = {12,1,42};
    int k4 = 3;
    int ans4 = 53;
    assert(solution.maximumHappinessSum(happiness4, k4) == ans4);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}