#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int ans = -1;
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        std::vector<int> prev = intervals[0];

        for (auto& interval : intervals) {
            if (interval[0] < prev[1]) {
                ++ans;
            } else {
                prev = interval;
            }
        }

        return ans;
    }
};

/*
    1   2
    1   2   3
        2   3
            3   4

    Greedy approach -- sort the list first by interval end value, keep track of previous interval
    If the beginning of the next interval is less than the end of the previous, we can add 1 to our counter
    Otherwise update the previous interval with the current
*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> intervals1 = {{1,2},{2,3},{3,4},{1,3}};
    int ans1 = 1;
    assert(solution.eraseOverlapIntervals(intervals1) == ans1);

    std::vector<std::vector<int>> intervals2 = {{1,2},{1,2},{1,2}};
    int ans2 = 2;
    assert(solution.eraseOverlapIntervals(intervals2) == ans2);

    std::vector<std::vector<int>> intervals3 = {{1,2}, {2,3}};
    int ans3 = 0;
    assert(solution.eraseOverlapIntervals(intervals3) == ans3);


    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}