#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <queue>

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend) {
        // Min-heap to store the smallest available chairs
        std::priority_queue<int, std::vector<int>, std::greater<int>> availableChairs;
        int n = times.size();

        // Add chairs 0 to n-1 to the available chairs min-heap
        for (int idx = 0; idx < n; ++idx) {
            availableChairs.push(idx);
        }

        // We need to track the time when friends leave, so use a min-heap for departure events
        // The heap stores pairs (leaving time, chair number)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> leavingChairs;

        // Add original index to each friend for identification later
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i);
        }

        // Sort times by arrival times
        std::sort(times.begin(), times.end());

        for (int idx = 0; idx < n; ++idx) {
            int arrival = times[idx][0];
            int departure = times[idx][1];
            int friendIndex = times[idx][2];

            // Free up chairs from friends who are leaving before this friend arrives
            while (!leavingChairs.empty() && leavingChairs.top().first <= arrival) {
                availableChairs.push(leavingChairs.top().second);
                leavingChairs.pop();
            }

            // Assign the smallest available chair to the arriving friend
            int assignedChair = availableChairs.top();
            availableChairs.pop();

            // If the current friend is the targetFriend, return the assigned chair
            if (friendIndex == targetFriend) {
                return assignedChair;
            }

            // Push the departure time and assigned chair to the leavingChairs heap
            leavingChairs.push({departure, assignedChair});
        }

        return 0; // In case no chair is found (which shouldn't happen)
    }
};


/*
    Friend number is dictated by order in original times array
    Need to somehow pair times vector to the original index -- cannot use vectors as a key in an unordered_map though so idk how to link them together
    With times sorted by arrival times using a heap, we can determine the arrival order and keep track of active chairs
*/

int main() {
    Solution solution;

    std::vector<std::vector<int>> times1 = {{1,4}, {2,3}, {4,6}};
    int targetFriend1 = 1;
    int ans1 = 1;

    std::vector<std::vector<int>> times2 = {{3,10}, {1,5}, {2,6}};
    int targetFriend2 = 0;
    int ans2 = 2;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.smallestChair(times1, targetFriend1);
    int test2 = solution.smallestChair(times2, targetFriend2);
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