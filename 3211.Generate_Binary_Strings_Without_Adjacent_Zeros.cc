#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    std::vector<std::string> ans;

    std::vector<std::string> validStrings(int n) {
        generateSubstrings("", n);

        return ans;
    }

    void generateSubstrings(std::string currentNum, int n) {
        if (currentNum.size() >=2 && currentNum[currentNum.size() - 1] == '0' && currentNum[currentNum.size() - 2] == '0') {
            return;
        }

        if (currentNum.size() == n) {
            ans.push_back(currentNum);
            return;
        }

        // int digitsLeft = n - 1;
        generateSubstrings(currentNum + "0", n);
        generateSubstrings(currentNum + "1", n);
    }
};
/*

*/

int main() {
    Solution solution;

    int n1 = 3;
    std::vector<std::string> ans1 = {"010","011","101","110","111"};

    int n2 = 1;
    std::vector<std::string> ans2 = {"0", "1"};
    auto t0 = std::chrono::high_resolution_clock::now();
    std::vector<std::string> test1 = solution.validStrings(n1);
    std::vector<std::string> test2 = solution.validStrings(n2);
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