#include <iostream>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

// Current problem, graph replaces occurence of last seen relationship, need to change graph to vector of pairs of string,double 
// Then for each query, find a path from query[0] to query[1] using DFS, keep a running product

class Solution {
public:
    std::vector<double> ans;
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
    std::unordered_set<std::string> visited;
    // DFS function
    double findAndCalculatePath(std::string currNode, std::string targetNode, double runningProduct, int currQuery) {
        // Base case
        if (currNode == targetNode) return runningProduct;

        // Recursive case -- find path from currNode to targetNode
        if (visited.find(currNode) == visited.end()) {
            visited.insert(currNode);
            for (int i = 0; i < graph[currNode].size(); ++i) {
                double newProduct = runningProduct * graph[currNode][i].second;
                double newAns = findAndCalculatePath(graph[currNode][i].first, targetNode, newProduct, currQuery);
                if (newAns != -1.0) {
                    return newAns;
                }
            }
        }
        return -1.0;
    }

    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        // Represent graph using unordered_map<string, pair<string, double>

        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        // For each query, for query[0] (the "base" node)
        for (int i = 0; i < queries.size(); ++i) {
            if (graph.find(queries[i][0]) != graph.end() && graph.find(queries[i][1]) != graph.end()) {
                visited.clear();
                ans.push_back(findAndCalculatePath(queries[i][0], queries[i][1], 1.0, i));
            } else {
                ans.push_back(-1.0);
            }
        }

        // for (auto& vec : ans) {
        //     std::cout << vec << " ";
        // }
        return ans;
    }
};

/*
    equations[i] = [A, B] -- variable pairs in equations
    values[i] = A / B
    queries[j] = [C, D] --> C / D = ?
    Return answer to all queries, if a query cannot be determined return -1

    Using example 1:
    a / b = 2, b / c = 3, determine a / c, b / a, a / e, a / a
    a = 2b, b = 3c
    a / c = 2b / b/3 = 6
    b / a = a/2 / 2a/2 = 0.5
    a / e = -1, so on and so forth
*/

int main() {
    Solution solution;
    std::vector<std::vector<std::string>> equations1 = {{"a", "b"}, {"b", "c"}};
    std::vector<double> values1 = {2.0, 3.0};
    std::vector<std::vector<std::string>> queries1 = {{"a", "c"}, {"b", "a"}, {"a","e"}, {"a","a"}, {"x","x"}};
    std::vector<double> expected1 = {6.0, 0.5, -1.0, 1.0, -1.0};
    assert(solution.calcEquation(equations1, values1, queries1) == expected1);

    std::cout << "All tests passed!";
    return 0;
}