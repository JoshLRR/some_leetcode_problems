#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int m = score.size();
        std::priority_queue<std::pair<int, int>> scores;
        std::vector<std::string> ans(m, "");
        int n = 1;

        for (int idx = 0; idx < score.size(); ++idx) {
            scores.push({score[idx], idx});
        }

        while (!scores.empty()) {
            int idx = scores.top().second;
            scores.pop();
            switch (n) {
                case 1:
                    ans[idx] = "Gold Medal";
                    break;
                case 2:
                    ans[idx] = "Silver Medal";
                    break;
                case 3:
                    ans[idx] = "Bronze Medal";
                    break;
                default:
                    ans[idx] = std::to_string(n);
                    break;
            }
            ++n;
        }

        for (auto& val : ans) {
            std::cout << val << ", ";
        }
        std::cout << "\n";
        return ans;
    }
};

/*
Heap -- 
Push pairs of {score, index} into a heap.
For the first 3 scores in the heap, assign the according medal. Otherwise, assign its position in the heap as it gets pushed off
*/

int main() {
    Solution solution;
    std::vector<int> score1 = {5,4,3,2,1};
    std::vector<std::string> ans1 = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    std::vector<int> score2 = {10,3,8,9,4};
    std::vector<std::string> ans2 = {"Gold Medal","5","Bronze Medal","Silver Medal","4"};
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.findRelativeRanks(score1) == ans1);
    assert(solution.findRelativeRanks(score2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}