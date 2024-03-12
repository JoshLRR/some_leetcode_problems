#include <iostream>
#include <cassert>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> heap;

        for (auto& num : nums) {
            heap.push(num);
        }

        for (int i = 0; i < k - 1; ++i) {
            heap.pop();
        }

        std::cout << heap.top() << "\n";
        return heap.top();
    }
};
/*

*/

int main() {
    Solution solution;
    std::vector<int> nums1 = {3,2,1,5,6,4};
    int k1 = 2;
    int ans1 = 5;
    assert(solution.findKthLargest(nums1, k1) == ans1);

    std::vector<int> nums2 = {3,2,3,1,2,4,5,5,6};
    int k2 = 4;
    int ans2 = 4;
    assert(solution.findKthLargest(nums2, k2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}