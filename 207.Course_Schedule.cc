#include <iostream>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
class Solution {
public:
    bool dfs(int course) {
        if (visiting.find(course) != visiting.end()) return false;
        if (adjList[course].empty()) return true;

        visiting.insert(course);
        for (auto& node : adjList[course]) {
            if (!dfs(node)) return false;
        }
        visiting.erase(course);
        adjList[course] = {};

        return true;
    }

    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        for (auto& prereqs : prerequisites) {
            adjList[prereqs[0]].push_back(prereqs[1]);
            if (prereqs[0] == prereqs[1]) return false;
        }

        for (auto& course : adjList) {
            if (!dfs(course.first)) return false;
        }

        return true;
    }
private:
    std::unordered_map<int, std::vector<int>> adjList;
    std::unordered_set<int> visiting;
};
/*
    DFS

    Create graph's adjacency list using an unordered_map<int, vector<int>>
    
*/

int main() {
    Solution solution;
    int numCourses1 = 2;
    std::vector<std::vector<int>> prereqs1 = {{1,0}};
    assert(solution.canFinish(numCourses1, prereqs1) == true);

    int numCourses2 = 2;
    std::vector<std::vector<int>> prereqs2 = {{1,0}, {0,1}};
    assert(solution.canFinish(numCourses2, prereqs2) == false);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}