#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
        std::vector<std::vector<int>> newArray(m, std::vector<int>(n, 0));

        if (original.size() != m * n) return {};
        for (int idx = 0; idx < original.size(); ++idx) {
            // std::cout << idx / n <<  ", ";
            // std::cout << idx % n << "\n";
            newArray[idx / n][idx % n] = original[idx];
        }

        for (auto& row : newArray) {
            for (auto& num : row) {
                std::cout << num << ", ";
            }
            std::cout << "\n";
        }

        return newArray;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> arr1 = {1,2,3,4};
    std::vector<std::vector<int>> ans1 = {{1,2}, {3,4}};

    std::vector<int> arr2 = {1,2,3};
    std::vector<std::vector<int>> ans2 = {{1,2,3}};

    std::vector<int> arr3 = {1,2};
    std::vector<std::vector<int>> ans3 = {};

    std::vector<int> arr4 = {3};
    std::vector<std::vector<int>> ans4 = {};

    auto t0 = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<int>> test1 = solution.construct2DArray(arr1, 2, 2);
    std::vector<std::vector<int>> test2 = solution.construct2DArray(arr2, 1, 3);
    std::vector<std::vector<int>> test3 = solution.construct2DArray(arr3, 1, 1);
    std::vector<std::vector<int>> test4 = solution.construct2DArray(arr4, 1, 2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);
    assert(test4 == ans4);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}