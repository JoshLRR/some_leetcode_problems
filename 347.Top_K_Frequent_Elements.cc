#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> ans(k, 0);
        std::unordered_map<int,int> encounteredNums;

        auto comp = [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
            return a.first < b.first;
        };
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>>, decltype(comp)> encounteredCount(comp);

        for (auto& num : nums) {
            if (encounteredNums.find(num) != encounteredNums.end()) {
                ++encounteredNums[num];
            } else {
                encounteredNums[num] = 1;
            }
        }

        for (auto& group : encounteredNums) {
            encounteredCount.push({group.second, group.first});
        }

        for (int i = 0; i < k; ++i) {
            ans[i] = encounteredCount.top().second;
            encounteredCount.pop();
        }

        return ans;
    }
};

/*
    Assuming nums is sorted
    Keep track of curr num and count how many times it appears -- pair<int, int>
        Push into priority queue and sort by pair.first
    Pop k nums from heap into ans array
*/

int main() {
    Solution solution;

    std::vector<int> nums1 = {1,1,1,2,2,3};
    int k1 = 2;
    std::vector<int> ans1 = {1,2};
    assert(solution.topKFrequent(nums1, k1) == ans1);

    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> ans2 = {1};
    assert(solution.topKFrequent(nums2, k2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}