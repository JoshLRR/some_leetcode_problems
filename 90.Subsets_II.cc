#include <iostream>
#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> input1 = {1,2,2};
    std::vector<std::vector<int>> ans1 = {
        {},
        {1},
        {1,2},
        {1,2,2},
        {2},
        {2,2}
    };
    assert(solution.subsetsWithDup(input1) == ans1);

    std::vector<int> input2 = {0};
    std::vector<std::vector<int>> ans2 = {{}, {0}};
    assert(solution.subsetsWithDup(input2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}