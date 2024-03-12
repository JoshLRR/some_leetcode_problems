#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n + 1, 0);

        for (int i = 0; i <= n; ++i) {
            int j = i;
            int temp = 0;
            while (j != 0) {
                if (j & 1) ++temp;
                j >>= 1;
            }
            ans[i] = temp;
        }

        // for (auto& val : ans) {
        //     std::cout << val << " ";
        // }
        return ans;
    }
};

/*
    Initialize an array of size n + 1
    Iterate through each value
        while each value isn't 0, & with 1 to see if the LSB holds a 1, if so, increment a counter
        bitshift the value to the right to test next bit
    Assign value to the array
    return array
*/

int main() {
    Solution solution;

    int n1 = 2;
    std::vector<int> ans1 = {0,1,1};
    assert(solution.countBits(n1) == ans1);
    
    int n2 = 5;
    std::vector<int> ans2 = {0,1,1,2,1,2};
    assert(solution.countBits(n2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}