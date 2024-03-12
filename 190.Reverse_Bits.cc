#include <iostream>
#include <cassert>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans ^= n & 1;
            n >>= 1;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    uint32_t input1 = 0b00000010100101000001111010011100;
    uint32_t ans1 = 0b00111001011110000010100101000000;
    assert(solution.reverseBits(input1) == ans1);

    uint32_t input2 = 0b11111111111111111111111111111101;
    uint32_t ans2 = 0b10111111111111111111111111111111;
    assert(solution.reverseBits(input2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}