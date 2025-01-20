#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <sstream>

class Solution {
public:
    std::string getEncryptedString(std::string s, int k) {
        std::string ans = "";
        std::stringstream ss;

        int n = s.size();

        for (int idx = 0; idx < n; ++idx) {
            int temp = (idx + k) % n;
            ss << s[temp];
            // std::cout << temp << ", ";
        }
        // std::cout << "\n";

        return ss.str();
    }
};
/*

*/

int main() {
    Solution solution;

    std::string s1 = "dart";
    int k1 = 3;
    std::string ans1 = "tdar";

    std::string s2 = "aaa";
    int k2 = 1;
    std::string ans2 = "aaa";

    auto t0 = std::chrono::high_resolution_clock::now();
    std::string test1 = solution.getEncryptedString(s1, k1);
    std::string test2 = solution.getEncryptedString(s2, k2);
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