#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int maxProfitAssignment(std::vector<int>& difficulty, std::vector<int>& profit, std::vector<int>& worker) {
        std::vector<std::pair<int,int>> jobs;
        int n = profit.size();
        int ans = 0;
        int idx = 0;
        int best = 0;

        for (int jdx = 0; jdx < n; ++jdx) {
            jobs.push_back({difficulty[jdx], profit[jdx]});
        }

        std::sort(jobs.begin(), jobs.end());
        std::sort(worker.begin(), worker.end());

        for (int& ability : worker) {
            while (idx < n && ability >= jobs[idx].first) {
                best = std::max(jobs[idx++].second, best);
            }
            ans += best;
        }

        return ans;
    }
};

int main() {
    Solution solution;

    std::vector<int> difficulty1 = {2,4,6,8,10};
    std::vector<int> profit1 = {10,20,30,40,50};
    std::vector<int> worker1 = {4,5,6,7};
    int ans1 = 100;

    std::vector<int> difficulty2 = {85,47,57};
    std::vector<int> profit2 = {24,66,99};
    std::vector<int> worker2 = {40,25,25};
    int ans2 = 0;

    std::vector<int> difficulty3 = {5,50,92,21,24,70,17,63,30,53};
    std::vector<int> profit3 = {68,100,3,99,56,43,26,93,55,25};
    std::vector<int> worker3 = {96,3,55,30,11,58,68,36,26,1};
    int ans3 = 765;
    

    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.maxProfitAssignment(difficulty1, profit1, worker1);
    int test2 = solution.maxProfitAssignment(difficulty2, profit2, worker2);
    int test3 = solution.maxProfitAssignment(difficulty3, profit3, worker3);
    auto end = std::chrono::high_resolution_clock::now();
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}