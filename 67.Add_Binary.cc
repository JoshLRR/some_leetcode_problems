#include <iostream>
#include <cassert>
#include <sstream>

class Solution {
public:
    std::string addBinary(std::string& a, std::string& b) {
        std::string ans = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            ans += (sum % 2) + '0';
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    std::string a1 = "11";
    std::string b1 = "1";
    std::string ans1 = "100";
    assert(solution.addBinary(a1,b1) == ans1);

    std::string a2 = "1010";
    std::string b2 = "1011";
    std::string ans2 = "10101";
    assert(solution.addBinary(a2,b2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}