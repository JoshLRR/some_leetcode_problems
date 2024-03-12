#include <iostream>
#include <cassert>
#include <queue>
class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap2;
        std::vector<std::vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();

        for (auto& val : nums1) {
            heap1.push(val);
        }

        for (auto& val : nums2) {
            heap2.push(val);
        }

        for (int i = 0; i < k; ++i) {
            ans.push_back({heap1.top(), heap2.top()});
            if (heap1.top() > heap2.top()) {
                heap1.pop();
            } else if (heap2.top() > heap1.top()) {
                heap2.pop();
            } else {
                heap1.pop();
            }
        }

        for (auto& set : ans) {
            for (auto& val : set) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
        std::cout << "done" << "\n";
        return ans;
    }
};

/*
    Min heap for each array, pop top of heap with larger value after creating pair
    jk values can be reused
*/

int main() {
    Solution solution;
    std::vector<int> numsa1 = {1,7,11};
    std::vector<int> numsa2 = {2,4,6};
    int k1 = 3;
    std::vector<std::vector<int>> ans1 = {{1,2}, {1,4}, {1,6}};
    assert(solution.kSmallestPairs(numsa1, numsa2, k1) == ans1);

    std::vector<int> numsB1 = {1,1,2};
    std::vector<int> numsB2 = {1,2,3};
    int k2 = 2;
    std::vector<std::vector<int>> ans2 = {{1,1}, {1,1}};
    assert(solution.kSmallestPairs(numsB1, numsB2, k2) == ans2);

    std::vector<int> numsC1 = {1,2,4,5,6};
    std::vector<int> numsC2 = {3,5,7,9};
    int k3 = 3;
    std::vector<std::vector<int>> ans3 = {{1,3}, {2,3}, {1,5}};
    assert(solution.kSmallestPairs(numsC1, numsC2, k3) == ans3);

    std::cout << "\033[32mAll tests passed!\033[0m";
    return 0;
}