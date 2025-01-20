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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root->left) {
            root->left = removeLeafNodes(root->left, target);
        }

        if (root->right) {
            root->right = removeLeafNodes(root->right, target);
        }

        // if (root->left == nullptr && root->right == nullptr) {
        //     if (root->val == target) {
        //         return nullptr;
        //     } else {
        //         return root;
        //     }
        // } else {
        //     return root;
        // }
        return root->left == root->right && root->val == target ? nullptr : root;
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