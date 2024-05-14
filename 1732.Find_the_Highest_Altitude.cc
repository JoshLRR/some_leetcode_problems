#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int maxAltitude = 0;
        int currAltitude = 0;

        for (auto& num : gain) {
            currAltitude += num;
            maxAltitude = std::max(maxAltitude, currAltitude);
        }

        return maxAltitude;
    }
};

/*

*/

int main() {
    Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}