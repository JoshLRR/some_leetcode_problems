#include <iostream>
#include <cassert>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;
        for (auto& num : nums) {
            ans ^= num;
        }    

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> input1 = {2,2,1};
    int ans1 = 1;
    assert(solution.singleNumber(input1) == ans1);

    std::vector<int> input2 = {4,1,2,1,2};
    int ans2 = 4;
    assert(solution.singleNumber(input2) == ans2);

    std::vector<int> input3 = {1};
    int ans3 = 1;
    assert(solution.singleNumber(input3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}