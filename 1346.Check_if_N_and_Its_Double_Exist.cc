#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {

        // Count zeros first
        int zeroCount = 0;
        for (int num : arr) {
            if (num == 0) {
                ++zeroCount;
            }
        }
        // If there are at least two zeros, return true
        if (zeroCount >= 2) {
            return true;
        }
        std::vector<int> arrCopy = arr;
        std::sort(arrCopy.begin(), arrCopy.end());

        for (auto& num : arr) {
            if (num == 0) {
                continue;
            }
            int left = 0;
            int right = arr.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arrCopy[mid] > (num * 2)) {
                    right = mid - 1;
                } else if (arrCopy[mid] < (num * 2)) {
                    left = mid + 1;
                } else {
                    // std::cout << "Found copyArr[mid]: " << arrCopy[mid] << " and num * 2 is: " << num * 2 << "\n";
                    return true;
                }
            }
        }

        return false;        
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> arr1 = {10,2,5,3};
    bool ans1 = true;

    std::vector<int> arr2 = {3,1,7,11};
    bool ans2 = false;

    std::vector<int> arr3 = {-2,0,10,-19,4,6,-8};
    bool ans3 = false;

    std::vector<int> arr4 = {0,0};
    bool ans4 = true;

    auto t0 = std::chrono::high_resolution_clock::now();
    bool test1 = solution.checkIfExist(arr1);
    bool test2 = solution.checkIfExist(arr2);
    bool test3 = solution.checkIfExist(arr3);
    bool test4 = solution.checkIfExist(arr4);
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