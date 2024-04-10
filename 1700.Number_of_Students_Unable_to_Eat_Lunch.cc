#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class Solution {
public:
    // int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
    //     std::queue<int> line;

    //     for (auto& student : students) {
    //         line.push(student);
    //     }

    //     for (auto& sandwich : sandwiches) {
    //         int lineShuffle = 0;
    //         while (line.front() != sandwich) {
    //             if (lineShuffle > line.size()) {
    //                 // std::cout << "returning line size: " << line.size() << "\n";
    //                 return line.size();
    //             }
    //             line.push(line.front());
    //             line.pop();
    //             ++lineShuffle;
    //         }
            
    //         line.pop();
    //     }

    //     return line.size();
    // }
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        // Count the number of students preferring each type of sandwich
        int preferences[2] = {0, 0};
        for (int student : students) {
            preferences[student]++;
        }

        // Iterate through each sandwich in the stack
        for (int sandwich : sandwiches) {
            // If no students prefer the current sandwich type, break
            if (preferences[sandwich] == 0) {
                break;
            }
            // A student gets their preferred sandwich
            preferences[sandwich]--;
        }

        // The number of students who can't get their preferred sandwich
        // is the sum of the remaining students preferring each type
        return preferences[0] + preferences[1];
    }
};
/*

*/

int main() {
    Solution solution;

    std::vector<int> students1 = {1,1,0,0};
    std::vector<int> sandwiches1 = {0,1,0,1};
    std::vector<int> students2 = {1,1,1,0,0,1};
    std::vector<int> sandwiches2 = {1,0,0,0,1,1};
    
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.countStudents(students1, sandwiches1) == 0);
    assert(solution.countStudents(students2, sandwiches2) == 3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}