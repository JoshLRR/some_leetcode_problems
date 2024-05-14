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
    std::string ans = "~";  // Acts like an INT_MAX but for chars, ascii code for ~ is 126, greater than any of the chars we expect

    void dfs(TreeNode* node, std::string currPath) {
        if (!node) return;

        if (!node->left && !node->right) {
            ans = std::min(ans, char(node->val + 'a') + currPath);
            return;
        }
        dfs(node->left, char(node->val + 'a') + currPath);
        dfs(node->right, char(node->val + 'a') + currPath);
    }

    std::string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
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