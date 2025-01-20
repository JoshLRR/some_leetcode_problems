#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        // Create adjacency list
        std::unordered_map<int,std::vector<std::pair<int,int>>> adjList;
        for (int idx = 0; idx < times.size(); ++idx) {
            auto curr = times[idx];
            adjList[curr[0]].push_back({curr[1], curr[2]});
        }

        // Initialize distances and priority queue
        std::vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [current_dist, u] = pq.top();
            pq.pop();

            if (current_dist > dist[u]) {
                continue;
            }
            // Update distances to neighboring nodes
            for (const auto& [v, weight] : adjList[u]) {
                int distance = current_dist + weight;
                if (distance < dist[v]) {
                    dist[v] = distance;
                    pq.emplace(distance, v);
                }
            }

        }

        // Evaluate result        
        int max_dist = 0;
        for (int idx = 1; idx <= n; ++idx) {
            if (dist[idx] == INT_MAX) {
                return -1;
            }
            max_dist = std::max(max_dist, dist[idx]);
        }
        return max_dist;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> times1 = {{2,1,1}, {2,3,1}, {3,4,1}};
    int n1 = 4;
    int k1 = 2;
    int ans1 = 2;
    std::vector<std::vector<int>> times2 = {{1,2,1}};
    int n2 = 2;
    int k2 = 1;
    int ans2 = 1;
    std::vector<std::vector<int>> times3 = {{1,2,1}};
    int n3 = 2;
    int k3 = 3;
    int ans3 = -1;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.networkDelayTime(times1, n1, k1) == ans1);
    assert(solution.networkDelayTime(times2, n2, k2) == ans2);
    assert(solution.networkDelayTime(times3, n3, k3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}