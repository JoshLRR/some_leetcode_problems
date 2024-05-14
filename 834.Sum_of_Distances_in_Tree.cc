#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> adjList;
    std::vector<int> counter, ans;

    void dfs(int idx, int p = -1) {
        for (auto& node : adjList[idx]) {
            if (node == p) continue;
            dfs(node, idx);
            counter[idx] += counter[node];
            ans[idx] += ans[node] + counter[node];
        }
        counter[idx] += 1;
    }

    void dfs2(int idx, int n, int p = -1) {
        for (auto& node : adjList[idx]) {
            if (node == p) continue;
            ans[node] = ans[idx] - counter[node] + n - counter[node];
            dfs2(node, n, idx);
        }
    }

    std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
        adjList.resize(n);

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        ans.resize(n);
        counter.resize(n);
        dfs(0);
        dfs2(0, n);

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;
    int n1 = 6;
    std::vector<std::vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    std::vector<int> ans1 = {8,12,6,10,10,10};
    int n2 = 1;
    std::vector<std::vector<int>> edges2 = {};
    std::vector<int> ans2 = {0};
    int n3 = 2;
    std::vector<std::vector<int>> edges3 = {{1,0}};
    std::vector<int> ans3 = {1,1};

    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.sumOfDistancesInTree(n1,edges1) == ans1);
    assert(solution.sumOfDistancesInTree(n2,edges2) == ans2);
    assert(solution.sumOfDistancesInTree(n3,edges3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}