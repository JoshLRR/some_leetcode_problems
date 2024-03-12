#include <iostream>
#include <cassert>
#include <queue>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> money(n);

        for (int i = 0; i < n; ++i) {
            money[i].first = capital[i];
            money[i].second = profits[i];
        }

        std::sort(money.begin(), money.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
            return a.first < b.first;
        });

        std::priority_queue<int> sortedPotentialProfits;
        int current = 0;
        // if (k > n) k = n; // Need to remove pairs as a project is completed this is too jank
        for (int i = 0; i < k; ++i) {
            // Add projects that can be afforded
            while(current < n && money[current].first <= w) {
                sortedPotentialProfits.push(money[current].second);
                ++current;
            }
            // If no projects can be afforded break
            if (sortedPotentialProfits.empty()) {
                break;
            }
            // Update capital with the most profitable
            w += sortedPotentialProfits.top();
            sortedPotentialProfits.pop();
        }
        std::cout << "Returning final: " << w << "\n";
        return w;
    }
};

// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
//         int n = profits.size();
//         std::vector<std::pair<int, int>> projects(n);
//         for (int i = 0; i < n; ++i) {
//             projects[i] = {capital[i], profits[i]};
//         }

//         std::sort(projects.begin(), projects.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
//             return a.first < b.first;
//         });

//         std::priority_queue<int> pq;
//         int current = 0;
//         for (int i = 0; i < k; ++i) {
//             // Add projects that can now be afforded
//             while (current < n && projects[current].first <= w) {
//                 pq.push(projects[current].second);
//                 current++;
//             }

//             // If no projects can be afforded, break
//             if (pq.empty()) {
//                 break;
//             }

//             // Update capital with the most profitable project
//             w += pq.top();
//             pq.pop();
//         }

//         return w;
//     }
// };
/*
    k -- projects that can be completed
    w -- Available capital
    profits -- profit from project_i                
    capital -- Capital required to start project -- is not subtracted from w

    put capital | profits in pairs
    Sort pairs in ascending order by capital
    Priority queue for profits of projects that can be afforded

    edge case: Cannot afford to start any projects
*/

int main() {
    Solution solution;
    int k1 = 2;
    int w1 = 0;
    std::vector<int> profits1 = {1,2,3};
    std::vector<int> capital1 = {0,1,1};
    int ans1 = 4;

    int k2 = 3;
    int w2 = 0;
    std::vector<int> profits2 = {1,2,3};
    std::vector<int> capital2 = {0,1,2};
    int ans2 = 6;

    int k3 = 1;
    int w3 = 0;
    std::vector<int> profits3 = {1,2,3};
    std::vector<int> capital3 = {1,1,2};
    int ans3 = 0;

    int k4 = 10;
    int w4 = 0;
    std::vector<int> profits4 = {1,2,3};
    std::vector<int> capital4 = {0,1,2};
    int ans4 = 6;

    int k5 = 2;
    int w5 = 0;
    std::vector<int> profits5 = {1,2,3};
    std::vector<int> capital5 = {0,9,10};
    int ans5 = 1;
    assert(solution.findMaximizedCapital(k1,w1,profits1,capital1) == ans1);
    assert(solution.findMaximizedCapital(k2,w2,profits2,capital2) == ans2);
    assert(solution.findMaximizedCapital(k3,w3,profits3,capital3) == ans3);
    assert(solution.findMaximizedCapital(k4,w4,profits4,capital4) == ans4);
    assert(solution.findMaximizedCapital(k5,w5,profits5,capital5) == ans5);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}