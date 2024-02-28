#include <iostream>
#include <cassert>

class Solution {
public:
    std::vector<std::vector<int>> ans;

    void dfs(int startIndex, std::vector<int>& nums) {
        // Base Case
        if (startIndex == nums.size() - 1) {
            ans.push_back(nums);
        }

        // Recursive Case
        for (int i = startIndex; i < nums.size(); ++i) {
            std::swap(nums[startIndex], nums[i]);
            dfs(startIndex + 1, nums);
            std::swap(nums[i], nums[startIndex]);
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> currentCombo;
        dfs(0, nums);

        // for (auto& val : ans) {
        //     for (auto& vec : val) {
        //         std::cout << vec << " ";
        //     }
        //     std::cout << ",";
        // }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<std::vector<int>> expected1 = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2}}; 
    assert(solution.permute(nums1) == expected1);

    std::cout << "All tests passed!";
    return 0;
}