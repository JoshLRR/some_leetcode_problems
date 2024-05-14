#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        curr *= 10;
        curr += node->val;

        if (!node->left && !node->right) {
            return curr;
        }


        return dfs(node->left, curr) + dfs(node->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        if (!root->left && !root->right) { 
            return root->val;
        }
        return dfs(root->left, root->val) + dfs(root->right, root->val);
    }
};

/*

*/

int main() {
    Solution solution;

    auto t0 = std::chrono::high_resolution_clock::now();
    
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}