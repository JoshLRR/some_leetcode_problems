#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>
#include <queue>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        std::priority_queue<int> numHeap(nums.begin(), nums.end());
        long long ans = 0;

        for (int idx = 0; idx < k; ++idx) {
            int temp = numHeap.top();
            numHeap.pop();
            ans += temp;
            // std::cout << "Inserting " << std::ceil((double)temp / 3.0) << " back into the heap, the top is now ";
            temp = std::ceil((double)temp / 3.0);
            numHeap.push(temp);
            // std::cout << temp << "\n";
        }

        // std::cout << ans << "\n";
        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {10,10,10,10,10};
    int k1 = 5;
    int ans1 = 50;

    std::vector<int> nums2 = {1,10,3,3,3};
    int k2 = 3;
    int ans2 = 17;

    auto t0 = std::chrono::high_resolution_clock::now();
    int test1 = solution.maxKelements(nums1, k1);
    int test2 = solution.maxKelements(nums2, k2);
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