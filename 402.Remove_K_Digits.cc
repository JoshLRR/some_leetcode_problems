#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>
#include <stack>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        if (num.length() <= k) {
            return "0";
        }
        if (k == 0) {
            return num;
        }

        std::string ans = "";
        std::stack<char> stack;
        stack.push(num[0]);

        for (int i = 1; i < num.length(); ++i) {
            while (k > 0 && !stack.empty() && num[i] < stack.top()) {
                --k;
                stack.pop();
            }

            stack.push(num[i]);
            if (stack.size() == 1 && num[i] == '0') {
                stack.pop();
            }
        }        

        while (k && !stack.empty()) {
            --k;
            stack.pop();
        }

        while (!stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }

        std::reverse(ans.begin(), ans.end());

        if (ans.length() == 0) {
            return "0";
        }

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::string num1 = "1432219";
    int k1 = 3;
    std::string ans1 = "1219";
    std::string num2 = "10200";
    int k2 = 1;
    std::string ans2 = "200";
    std::string num3 = "10";
    int k3 = 2;
    std::string ans3 = "0";
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.removeKdigits(num1, k1) == ans1);
    assert(solution.removeKdigits(num2, k2) == ans2);
    assert(solution.removeKdigits(num3, k3) == ans3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}