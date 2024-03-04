#include <iostream>
#include <cassert>
#include <sstream>

class Solution {
public:
    std::string maximumOddBinaryNumber(std::string s) {
        int numOnes = 0;
        std::stringstream ss;
        std::string ans;
        for (auto& num : s) {
            if (num == '1') ++numOnes;
        }

        for (int i = 0; i < numOnes - 1; ++i) {
            ss << '1';
        }

        for (int i = numOnes - 1; i < s.size() - 1; ++i) {
            ss << '0';
        }
        ss << '1';
        ans = ss.str();
        std::cout << ans << "\n";
        return ans;   
    }
};

/*
    Count number of 1s
    For every 1 after the first, place them in the most significant bits
    Place the last 1 in the least significant bit
*/

int main() {
    Solution solution;
    
    assert(solution.maximumOddBinaryNumber("010") == "001");
    assert(solution.maximumOddBinaryNumber("0101") == "1001");

    std::cout << "All tests passed!";
    return 0;
}