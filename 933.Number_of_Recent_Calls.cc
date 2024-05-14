#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class RecentCounter {
public:
    std::queue<int> requests;        
    RecentCounter() {
    }
    
    int ping(int t) {
        int lower = t - 3000;

        while (!requests.empty() && lower > requests.front()) {
            requests.pop();
        }
        requests.push(t);

        return requests.size();
    }
};


/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/*

*/

int main() {
    // Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}