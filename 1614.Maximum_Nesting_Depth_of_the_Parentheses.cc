#include <iostream>
#include <cassert>

class Solution {
public:
    int maxDepth(std::string s) {
        int parenDepth = 0;
        int ans = INT_MIN;
        for (char& chara : s) {
            if (chara == '(') {
                ++parenDepth;
                ans = std::max(parenDepth, ans);
            } else if (chara == ')') {
                --parenDepth;
            }
        }


        std::cout << ans << "\n";
        if (ans == INT_MIN) {
            return 0;
        } else {
            return ans;
        }
    }
};

/*

*/

int main() {
    Solution solution;

    std::string s1 = "(1+(2*3)+((8)/4))+1";
    int ans1 = 3;
    std::string s2 = "(1)+((2))+(((3)))";
    int ans2 = 3;
    std::string s3 = "1";
    int ans3 = 0;
    assert(solution.maxDepth(s1) == ans1);
    assert(solution.maxDepth(s2) == ans2);
    assert(solution.maxDepth(s3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}