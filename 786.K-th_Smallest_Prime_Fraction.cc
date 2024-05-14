#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

// class Solution {
// public:
//     std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
//         auto comp = [](const std::pair<double, std::pair<int, int>>& a, const std::pair<double, std::pair<int, int>>& b) {
//             return a.first > b.first; // Min-heap based on the value of the fraction
//         };
//         std::priority_queue<std::pair<double, std::pair<int, int>>, 
//                             std::vector<std::pair<double, std::pair<int, int>>>, 
//                             decltype(comp)> minHeap(comp);

//         int n = arr.size();

//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 double res = static_cast<double>(arr[i]) / arr[j];
//                 minHeap.push({res, {arr[i], arr[j]}});
//             }
//         }

//         for (int idx = 1; idx < k; ++idx) {
//             minHeap.pop();
//         }

//         return {minHeap.top().second.first, minHeap.top().second.second};
//     }
// };

class Solution {
public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1, mid;
        std::vector<int> res;

        while (left <= right) {
            mid = left + (right - left) / 2;
            int j = 1, total = 0, num = 0, den = 0;
            double maxFrac = 0;
            for (int i = 0; i < n; ++ i) {
                while (j < n && arr[i] >= arr[j] * mid) {
                    ++j;
                }
                
                total += n - j;

                if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                    maxFrac = arr[i] * 1.0 / arr[j];
                    num = i; den = j;
                }
            }

            if (total == k) {
                res = {arr[num], arr[den]};
                break;
            }

            if (total > k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return res;
    }
};

/*
First approach uses MinHeap and brute forces --
Create all fraction pairs and add to a minHeap, pop k-1 values to get the kth lowest value

Second approach uses binary search and is the optimal solution --

*/

int main() {
    Solution solution;
    std::vector<int> arr1 = {1,2,3,5};
    int k1 = 3;
    std::vector<int> ans1 = {2,5};
    std::vector<int> arr2 = {1,7};
    int k2 = 1;
    std::vector<int> ans2 = {1,7};
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.kthSmallestPrimeFraction(arr1, k1) == ans1);
    assert(solution.kthSmallestPrimeFraction(arr2, k2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}