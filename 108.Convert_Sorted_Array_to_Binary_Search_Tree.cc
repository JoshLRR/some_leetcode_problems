#include <iostream>
#include <cassert>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
private:
    TreeNode* dfs(const std::vector<int>& nums, int start, int end) {
        // Base Case -- empty subarray
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = dfs(nums, start, mid - 1);
        node->right = dfs(nums, mid + 1, end);

        return node;
    }
public:


    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};

/*
    Run dfs on root of each sub-tree
    Explore sub arrays to the left and right of the root
*/

// Test doesn't work
int main() {
    Solution solution;
    std::vector<int> nums1 = {-10, -3, 0, 5, 9};

    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(-3);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(-10);
    root->right->left = new TreeNode(5);
    assert(solution.sortedArrayToBST(nums1) == root);

    std::cout << "All tests passed!";
    return 0;
}