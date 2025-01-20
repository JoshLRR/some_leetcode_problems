#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <utility>

class MyCalendar {
public:
    std::vector<std::pair<int, int>> schedule = {};

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        int left = 0;
        int right = schedule.size() - 1;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
           
            if (start < schedule[mid].second && end > schedule[mid].first) {
                return false;
            }

            if (start >= schedule[mid].second) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        schedule.insert(schedule.begin() + left, {start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/*
    Idea 1: Sorted vector of pairs, use binary search to find a suitable start time then check for an intersection with the end time

*/

int main() {
    Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}