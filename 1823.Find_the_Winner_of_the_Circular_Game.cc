#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         std::queue<int> survivingFriends;

//         for (int idx = 1; idx <= n; ++idx) {
//             survivingFriends.push(idx);
//         }

//         while (survivingFriends.size() > 1) {
//             for (int idx = 0; idx < k - 1; ++idx) {
//                 survivingFriends.push(survivingFriends.front());
//                 survivingFriends.pop();
//             }
//             survivingFriends.pop();
//         }

//         std::cout << "Returning: " << survivingFriends.front() << "\n";
//         return survivingFriends.front();
//     }
// };

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Base case for the last remaining person

        // Iteratively calculate the position of the winner
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }

        return winner + 1; // Convert from 0-based to 1-based index
    }
};

/*
    The first solution uses a queue and simulates the problem.
    For the follow up problem that requires O(n) runtime and O(1) memory complexity, an iterative approach is used.
    
*/

int main() {
    Solution solution;

    int n1 = 5;
    int k1 = 2;
    int ans1 = 3;

    int n2 = 6;
    int k2 = 5;
    int ans2 = 1;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.findTheWinner(n1, k1);
    int test2 = solution.findTheWinner(n2, k2);
    auto end = std::chrono::high_resolution_clock::now();
    
    assert(test1 == ans1);
    assert(test2 == ans2);

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}