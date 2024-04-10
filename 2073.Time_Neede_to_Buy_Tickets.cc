#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int ans = 0;

        while (tickets[k] > 0) {
            for (auto& ticket : tickets) {
                if (ticket > 0) {
                    --ticket;
                    ++ans;
                    if (tickets[k] == 0) break;
                }

            }
            // for (auto& num : tickets) {
            //     std::cout << num << ", "; 
            // }
            // std::cout << "\n";
        }

        std::cout << ans << "\n";
        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> tickets1 = {2,3,2};
    int k1 = 2;
    int ans1 = 6;
    std::vector<int> tickets2 = {5,1,1,1};
    int k2 = 0;
    int ans2 = 8;
    std::vector<int> tickets3 = {84,49,5,24,70,77,87,8};
    int k3 = 3;
    int ans3 = 154;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.timeRequiredToBuy(tickets1, k1) == ans1);
    assert(solution.timeRequiredToBuy(tickets2, k2) == ans2);
    assert(solution.timeRequiredToBuy(tickets3, k3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}