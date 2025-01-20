#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        int pivotPoint = 0;
        int n = s.size();
        for (int idx = 0; idx < n; ++idx) {
            std::string rotatedString = "";

            for (int jdx = pivotPoint; jdx < n; ++jdx) {
                rotatedString += s[jdx];
            }
            for (int jdx = 0; jdx < pivotPoint; ++jdx) {
                rotatedString += s[jdx];
            }

            ++pivotPoint;

            // std::cout << "RotatedString: " << rotatedString << "\n";
            if (rotatedString == goal) return true;
        }

        return false;
    }
};

/*
    Can be done in a one liner by adding s to s, then looking for goal
    
    bool rotateString(string A, string B) {                
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }   

    ex.
    string: abcde   goal: cdeab
    s + s: abcdeabcde
             _____      -- Can be found right there

    Can use string class's find() function
*/

int main() {
    Solution solution;

    std::string s1 = "abcde";
    std::string goal1 = "cdeab";
    bool ans1 = true;

    std::string s2 = "abcde";
    std::string goal2 = "abced";
    bool ans2 = false;

    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.rotateString(s1, goal1);
    bool test2 = solution.rotateString(s2, goal2);
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