#include <iostream>
#include <cassert>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int ans = 0;
        bool counting = false;

        for (int idx = s.size() - 1; idx >= 0; --idx) {
            if (s[idx] != ' ') {
                counting = true;
                ++ans;
            } else if (counting) {
                break;
            }
        }

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;
    std::string s1 = "Hello World";
    int ans1 = 5;
    assert(solution.lengthOfLastWord(s1) == ans1);

    std::string s2 = "   fly me   to   the moon  ";
    int ans2 = 4;
    assert(solution.lengthOfLastWord(s2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}