#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        std::vector<std::vector<int>> ans;

        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        ans.push_back(intervals[0]);

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = std::max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        for (auto& group : ans) {
            std::cout << group[0] << "," << group[1] << "\n";
        }
        std::cout << "-------\n";
        return ans;
    }
};

/*
    0 1 2 3
        2 3 4 5 6
    ==
    0 1 2 3 4 5 6

    if front of second interval is behind the end of the first, compare the back of the first (3) and the back of the current interval (6), the larger becomes the end of the original interval
*/

int main() {
    Solution solution;

    std::vector<std::vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> ans1 = {{1,6},{8,10},{15,18}};
    assert(solution.merge(intervals1) == ans1);

    std::vector<std::vector<int>> intervals2 = {{1,4},{4,5}};
    std::vector<std::vector<int>> ans2 = {{1,5}};
    assert(solution.merge(intervals2) == ans2);

    std::vector<std::vector<int>> intervals3 = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    std::vector<std::vector<int>> ans3 = {{1,10}};
    assert(solution.merge(intervals3) == ans3);

    std::vector<std::vector<int>> intervals4 = {{2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}};
    std::vector<std::vector<int>> ans4 = {{1,3},{4,7}};
    assert(solution.merge(intervals4) == ans4);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}