#include <iostream>
#include <cassert>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    assert(solution.lowestCommonAncestor(root, root->left, root->right) == root);
    assert(solution.lowestCommonAncestor(root, root->left, root->left->right->right) == root->left);
    assert(solution.lowestCommonAncestor(root2, root2, root2->left) == root);

    std::cout << "All tests passed!";
    return 0;
}