#include <iostream>
#include <cassert>
#include <bitset>


class Solution {
public:
    std::vector<int> grayCode(int n) {
        int m = std::pow(2,n);
        std::vector<int> ans;
        for (int i = 0; i < m; ++i) {
            ans.push_back(i ^ (i >> 1));
        }

        for(auto& num : ans) {
            std::cout << std::bitset<4>(num) << "\n";
        }
        return ans;
    }
};

/*

*/

int main() {
    Solution solution;
    int input1 = 2;
    std::vector<int> ans1 = {0,1,3,2};
    assert(solution.grayCode(input1) == ans1);

    int input2 = 1;
    std::vector<int> ans2 = {0,1};
    // assert(solution.grayCode(input2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}