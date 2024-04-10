#include <iostream>
#include <cassert>
#include <vector>

class Solution {
public:
    // bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    //     bool lookingForOne;
    //     int flowersPlaced = 0;
    //     int bedSize = flowerbed.size();

    //     if (n == 0) {
    //         return true;
    //     }

    //     if (bedSize == 1 && flowerbed[0] == 0 && n == 1) {
    //         return true;
    //     }

    //     if (bedSize == 1 && flowerbed[0] == 0 && n == 0) {
    //         return false;
    //     }

    //     if (flowerbed[0] == 0 && flowerbed[1] == 0) {
    //         ++flowersPlaced;
    //         flowerbed[0] = 1;
    //     }

    //     for (int i = 1; i < bedSize - 1; ++i) {
    //         if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
    //             flowerbed[i] = 1;
    //             ++flowersPlaced;
    //         }
    //     }

    //     if (flowerbed[bedSize - 1] == 0 && flowerbed[bedSize - 2] == 0) {
    //         ++flowersPlaced;
    //     }

    //     if (flowersPlaced >= n) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }

        return n <= 0;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> flowerbed1 = {1,0,0,0,1};
    int n1 = 1;
    assert(solution.canPlaceFlowers(flowerbed1, n1) == true);

    std::vector<int> flowerbed2 = {1,0,0,0,1};
    int n2 = 2;
    assert(solution.canPlaceFlowers(flowerbed2, n2) == false);

    std::vector<int> flowerbed3 = {1,0,1,0,1,0,1};
    int n3 = 1;
    assert(solution.canPlaceFlowers(flowerbed3, n3) == false);

    std::vector<int> flowerbed4 = {0,0,1,0,1};
    int n4 = 1;
    assert(solution.canPlaceFlowers(flowerbed4, n4) == true);

    std::vector<int> flowerbed5 = {0};
    int n5 = 1;
    assert(solution.canPlaceFlowers(flowerbed5, n5) == true);

    std::vector<int> flowerbed6 = {0};
    int n6 = 0;
    assert(solution.canPlaceFlowers(flowerbed6, n6) == true);


    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}