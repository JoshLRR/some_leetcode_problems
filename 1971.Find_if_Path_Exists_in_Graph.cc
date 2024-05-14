#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        std::unordered_map<int, std::vector<int>> adjList;

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        std::vector<bool> visited(n, 0);
        std::stack<int> stacky;
        stacky.push(source);
        visited[source] = 1;

        while(!stacky.empty()) {
            auto top = stacky.top();
            if (top == destination) return true;

            stacky.pop();
            for (auto& node : adjList[top]) {
                if (!visited[node]) {
                    visited[node] = true;
                    stacky.push(node);
                }
            }
        }

        return false;
    }
};

/*

*/

int main() {
    Solution solution;
    int n1 = 3;
    std::vector<std::vector<int>> edges1 = {{0,1}, {1,2}, {2,0}};
    int source1 = 0;
    int destination1 = 2;
    int n2 = 6;
    std::vector<std::vector<int>> edges2 = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int source2 = 0;
    int destination2 = 5;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.validPath(n1,edges1,source1,destination1) == true);
    assert(solution.validPath(n2,edges2,source2,destination2) == false);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}