#include <iostream>
#include <cassert>
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        // Non overlapping intervals before the start of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            ++i;
        }
        // All overlapping intervals are merged
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(intervals[i][0], newInterval[0]);
            newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            ++i;
        }
        ans.push_back(newInterval);
        // Non overlapping intervals after the end of newInterval
        while (i < n && intervals[i][0] > newInterval[1]) {
            ans.push_back(intervals[i]);
            ++i;
        }

        return ans;
    }
};

/*
    Look for interval that "fits" the first number of newInterval
    For the first "fitted" interval, compare newInterval[1] to the end of the interval. If newInterval[1] > currentInterval[1], then we know we can extend the current interval.
    Continue checking more intervals, if the start value of the next interval is less than newInterval[1], we can keep extending the interval. Check its last value and that's still smaller than newInterval[1], we can keep extending until we find a larger value. 
*/

int main() {
    Solution solution;

    std::vector<std::vector<int>> intervals1 = {{1,3}, {6,9}};
    std::vector<int> newInterval1 = {2,5};
    std::vector<std::vector<int>> ans1 = {{1,5}, {6,9}};
    assert(solution.insert(intervals1, newInterval1) == ans1);

    std::vector<std::vector<int>> intervals2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int> newInterval2 = {4,8};
    std::vector<std::vector<int>> ans2 = {{1,2},{3,10},{12,16}};
    assert(solution.insert(intervals2, newInterval2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}