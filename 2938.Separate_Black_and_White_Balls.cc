#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    long long minimumSteps(std::string s) {
        long long steps = 0;

        int left = 0;
        int right = s.length();

        while (left <= right) {
            if (s[left] == '1' && s[right] == '0') {
                steps += (right - left);
                ++left;
                --right;
            }
            else if (s[left] != '1') ++left;
            else if (s[right] != '0') --right;
        }

        // std::cout << steps << "\n";
        return steps;
    }
};

/*

*/

int main() {
    Solution solution;

    std::string s1 = "101";
    long long ans1 = 1;

    std::string s2 = "100";
    long long ans2 = 2;

    std::string s3 = "0111";
    long long ans3 = 0;
    auto t0 = std::chrono::high_resolution_clock::now();
    long long test1 = solution.minimumSteps(s1);
    long long test2 = solution.minimumSteps(s2);
    long long test3 = solution.minimumSteps(s3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}