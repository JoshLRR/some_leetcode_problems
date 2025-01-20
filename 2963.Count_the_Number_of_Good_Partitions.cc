#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class Solution {
public:
    long long numberOfWeeks(std::vector<int>& milestones) {
        auto cmp = [](const std::pair<int, int>& left, const std::pair<int, int>& right) {
            return left.first < right.first; // Max-heap behavior on the first element
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> maxHeap(cmp);

        int numWeeks = 0;

        // Can't work on the same project twice in a row
        // Can only finish one milestone per week
        for (int idx = 0; idx < milestones.size(); ++idx) {
            maxHeap.push({milestones[idx], idx});
        }

        std::pair<int,int> prevProject= {-1, -1};
        
        while (!maxHeap.empty()) {
            std::pair<int,int> currProject = maxHeap.top();
            --currProject.first;
            maxHeap.pop();  

            if (maxHeap.empty()) break;
            
            if (prevProject.first != -1) {
                maxHeap.push(prevProject);
            }

            prevProject = currProject;
            ++numWeeks;
        }


        std::cout << numWeeks << "\n";
        return numWeeks;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> milestones1 = {1,2,3};
    int ans1 = 6;

    std::vector<int> milestones2 = {5,2,1};
    int ans2 = 7;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.numberOfWeeks(milestones1);
    int test2 = solution.numberOfWeeks(milestones2);
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