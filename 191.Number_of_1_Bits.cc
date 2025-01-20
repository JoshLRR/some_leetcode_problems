#include <iostream>
#include <cassert>

class Solution {
public:
    // int hammingWeight(uint32_t n) {
    //     int count = 0;
    //     for (int i = 0; i < 32; ++i) {
    //         if (n & 1) ++count;
    //         n >>= 1;
    //     }

    //     return count;
    // }
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            ++count;
            n = n & (n - 1);
        }

        return count;

    }
};

int main() {
    Solution solution;
    // uint32_t input1 = 0b00000000000000000000000000001011;
    uint32_t input1 = 11;
    int ans1 = 3;
    assert(solution.hammingWeight(input1) == ans1);

    // uint32_t input2 = 0b00000000000000000000000010000000;
    uint32_t input2 = 128;
    int ans2 = 1;
    assert(solution.hammingWeight(input2) == ans2);


    // uint32_t input3 = 0b11111111111111111111111111111101;
    uint32_t input3 = 2147483645;
    int ans3 = 30;
    assert(solution.hammingWeight(input3) == ans3);
    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}