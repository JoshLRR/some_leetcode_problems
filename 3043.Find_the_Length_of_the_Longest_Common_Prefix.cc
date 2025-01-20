#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestCommonPrefix(std::vector<int>& arr1, std::vector<int>& arr2) {
        int longestPrefix = 0;
        std::unordered_set<int> arr1Prefixes;

        for (auto& num : arr1) {
            while (num > 0) {
                arr1Prefixes.insert(num);
                num /= 10;
            }
        }

        for (auto& num : arr2) {
            while (num > 0) {   
                if (arr1Prefixes.find(num) != arr1Prefixes.end()) {
                    int numDigits = std::log10(std::abs(num)) + 1;
                    longestPrefix = std::max(longestPrefix, numDigits);
                    // std::cout << "Found matching prefix " << num << " which has " << numDigits << " digits" << "\n";
                }
                num /= 10;
            }
        }

        // std::cout << longestPrefix << "\n";
        return longestPrefix;
    }
};

/*

*/

int main() {
    Solution solution;
    std::vector<int> arr1 = {1,10,100};
    std::vector<int> arr2 = {1000};
    int ans1 = 3;

    std::vector<int> arr3 = {1,2,3};
    std::vector<int> arr4 = {4,4,4};
    int ans2 = 0;
    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.longestCommonPrefix(arr1, arr2);
    int test2 = solution.longestCommonPrefix(arr3, arr4);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}