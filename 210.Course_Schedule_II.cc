#include <iostream>
#include <cassert>
#include <unordered_set>
#include <stack>

class Solution {
private:

public:
    void dfs() {

    }

    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> courseMap;

        for (auto& prereqs : prerequisites) {
            courseMap[prereqs[0]].push_back(prereqs[1]);
        }

        for (auto& course : courseMap) {
            std::cout << "Course: " << course.first << " -> ";
            for (int idx = 0; idx < course.second.size(); ++idx) {
                std::cout << course.second[idx] << ", ";
            }
            std::cout << "\n";
        }

        return {};
    }
};

/*
    Represent prerequisite graph using an unordered_map<int, vector<int> to make adj list
    Courses are numbered from 0 to numCourses - 1

    Need to detect cycles, if a cycle is detected then we immediately know that it's impossible to finish all courses

    Use DFS on each course's prereq, add courses to a visited set as we go
*/

int main() {
    Solution solution;
    std::vector<std::vector<int>> prereqs1 = {{1,0}};
    std::vector ans1 = {0, 1};
    std::vector<std::vector<int>> prereqs2 = {{1,0}, {2,0}, {3,1}, {3,2}};
    std::vector ans2 = {0,2,1,3};
    std::vector<std::vector<int>> prereqs3 = {};
    std::vector ans3 = {0};
    // assert(solution.findOrder(2, prereqs1) == ans1);
    assert(solution.findOrder(4, prereqs2) == ans2);
    assert(solution.findOrder(1, prereqs3) == ans3);

    std::cout << "All tests passed!";
    return 0;
}