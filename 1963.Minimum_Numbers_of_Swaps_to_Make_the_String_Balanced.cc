#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <stack>

class Solution {
public:
    int minSwaps(std::string s) {
        std::stack<char> parenStack;
        int swaps = 0;

        for (auto& letter : s) {
            
        }

        return swaps;
    }
};

/*

*/

int main() {
    Solution solution;
    std::string s1 = "][][";
    int ans1 = 1;

    std::string s2 = "]]][[[";
    int ans2 = 2;

    std::string s3 = "[]";
    int ans3 = 0;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.minSwaps(s1);
    int test2 = solution.minSwaps(s2);
    int test3 = solution.minSwaps(s3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}