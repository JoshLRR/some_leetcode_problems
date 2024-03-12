#include <iostream>
#include <cassert>
#include <bitset>

// class Solution {
// public:
//     int getSum(int a, int b) {
//         int carryBit = 0;
//         std::cout << "a" << "\t\t\t" << "b" << "\t\t\t" << "carryBit" << "\n";
//         std::cout << std::bitset<8>(a) << " : " << std::bitset<8>(b) << " : " << std::bitset<8>(carryBit) << "\n";
//         while (b != 0) {
//             carryBit = a & b;
//             a = a ^ b;
//             b = carryBit << 1;
//             std::cout << std::bitset<8>(a) << " : " << std::bitset<8>(b) << " : " << std::bitset<8>(carryBit) << "\n";

//         }

//         return a;
//     }
// };

class Solution {
public:
    int getSum(int a, int b) {
        int carryBit = 0;

        while(b != 0) {
            carryBit = a & b;
            a = a ^ b;
            b = carryBit << 1;
        }

        return a;
    }
};

/*
    XOR adds but falls short if there's a carry bit
    & generates the correct carry bit, but needs to be shifted
*/

int main() {
    Solution solution;

    int a1 = 1;
    int b1 = 2;
    int ans1 = 3;
    assert(solution.getSum(a1,b1) == ans1);

    int a2 = 2;
    int b2 = 3;
    int ans2 = 5;
    assert(solution.getSum(a2,b2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}