#include <iostream>
#include <cassert>
#include <stack>
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) return nullptr;

    //     std::stack<TreeNode*> stack1;
    //     stack1.push(root);

    //     while (!stack1.empty()) {
    //         TreeNode* node = stack1.top();
    //         stack1.pop();

    //         TreeNode* temp = root->left;
    //         root->left = root->right;
    //         root->right = temp;

    //         if (node->left) stack1.push(node->left);
    //         if (node->right) stack1.push(root->right);
    //     }

    //     return root;
    // }
};

/*

*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}