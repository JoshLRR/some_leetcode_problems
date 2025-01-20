#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::vector<int> copiedArray = arr;        
        std::vector<int> ans;

        std::unordered_map<int, int> rank;
        std::sort(copiedArray.begin(), copiedArray.end());

        for (int& num : copiedArray) {
            rank.emplace(num, rank.size() + 1);
        }

        for (int idx = 0; idx < copiedArray.size(); ++idx) {
            copiedArray[idx] = rank[arr[idx]];
        }
        
        return copiedArray;
    }
};

/*
    
*/

int main() {
    Solution solution;
    std::vector<int> arr1 = {40,10,20,30};
    std::vector<int> ans1 = {4,1,2,3};

    std::vector<int> arr2 = {100,100,100};
    std::vector<int> ans2 = {1,1,1};

    std::vector<int> arr3 = {37,12,28,9,100,56,80,5,12};
    std::vector<int> ans3 = {5,3,4,2,8,6,7,1,3};
    auto t0 = std::chrono::high_resolution_clock::now();
    std::vector<int> test1 = solution.arrayRankTransform(arr1);
    std::vector<int> test2 = solution.arrayRankTransform(arr2);
    std::vector<int> test3 = solution.arrayRankTransform(arr3);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;
    assert(test1 == ans1);
    assert(test2 == ans2);
    assert(test3 == ans3);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}