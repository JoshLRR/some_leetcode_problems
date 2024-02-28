#include <iostream>
#include <cassert>

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int numShifts = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            ++numShifts;
        }

        /*
            left = 3 = 11
            right = 6 = 110

            11
            110
            >> 1
            1
            11
            >> 1
            0
            1
            --> 1
            0
            0
            numShifts = 3
            left = 0
            0 << 3 == 0
        */
        
        return left << numShifts;
    }
};
int main() {
    Solution solution;
    
    assert(solution.rangeBitwiseAnd(3, 6) == 0);
    assert(solution.rangeBitwiseAnd(5, 7) == 4);

    std::cout << "All tests passed!";
    return 0;
}