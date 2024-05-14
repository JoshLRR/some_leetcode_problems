#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

// class Solution {
// public:
//     double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
//         double ans = 0;
//         std::priority_queue<std::pair<double, int>, std::vector<std::pair<double,int>>, std::greater<std::pair<double,int>>> minHeap; 

//         for (int idx = 0; idx < quality.size(); ++idx) {
//             minHeap.push({1.0 * quality[idx] / wage[idx], idx});
//         }

//         // while (!minHeap.empty()) {
//         //     std::cout << minHeap.top().first << " : " << minHeap.top().second << "\n";
//         //     minHeap.pop();
//         // }

//         double ratio = 0;
//         for (int idx = 0; idx < k; ++idx) {
//             if (idx == 0) {
//                 ratio = minHeap.top().first;
//                 ans += wage[minHeap.top().second];
//                 std::cout << ans << "\n";
//             } else {
//                 std::cout << "Adding: " << quality[minHeap.top().second] / ratio << "\n";
//                 ans += quality[minHeap.top().second] / ratio ;
//             }
//             minHeap.pop();
//         }

//         std::cout << ans << "\n";
//         return ans;
//     }
// };

class Solution {
public:
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        std::vector<std::pair<double, int>> workers;
        for (int i = 0; i < n; ++i) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        std::sort(workers.begin(), workers.end());

        std::priority_queue<int> max_heap;
        long long total_quality = 0;
        double min_cost = std::numeric_limits<double>::max();

        for (auto& worker : workers) {
            double ratio = worker.first;
            int q = worker.second;

            max_heap.push(q);
            total_quality += q;

            if (max_heap.size() > k) {
                total_quality -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == k) {
                min_cost = std::min(min_cost, ratio * total_quality);
            }
        }

        std::cout << min_cost << "\n";
        return min_cost;
    }
};


/*
    == pay must be proportional to quality == 
    O(n logn) solution -- Min Heap to find minimum ratio of quality/wage
    Loop through each idx, push quality/wage to a minHeap
*/

int main() {
    Solution solution;
    std::vector<int> quality1 = {10,20,5};
    std::vector<int> wage1 = {70,50,30};
    int k1 = 2;
    double ans1 = 105.00000;
    std::vector<int> quality2 = {3,1,10,10,1};
    std::vector<int> wage2 = {4,8,2,2,7};
    int k2 = 3;
    double ans2 = 30.66667;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.mincostToHireWorkers(quality1, wage1, k1) - ans1 < 10e5);
    assert(solution.mincostToHireWorkers(quality2, wage2, k2) - ans2 < 10e5);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}