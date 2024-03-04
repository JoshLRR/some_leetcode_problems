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
    TreeNode* findAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr || node == p || node == q) {
            return node;
        }

        TreeNode* left = findAncestor(node->left, p, q);
        TreeNode* right = findAncestor(node->right, p, q);

        if (left && right) {
            return node;
        } else if (!left && right) {
            return right;
        } else if (left && !right) {
            return left;
        }

        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findAncestor(root, p, q);
    }
};

/*
    Find lowest node that has both p and q as children
*/

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
    assert(solution.lowestCommonAncestor(root2, root2, root2->left) == root2);

    std::cout << "All tests passed!";
    return 0;
}