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
public:
    bool dfs(TreeNode* node, double left, double right) {
        if (!node) return true;

        if (node->val <= left || node->val >= right) return false;
        return dfs(node->left, left, node->val) && dfs(node->right, node->val, right);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return false;

        return dfs(root, -INFINITY, INFINITY);
    }
};
/*
    
*/

int main() {
    Solution solution;

    // Test case 1: True example
    TreeNode* root1 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    assert(solution.isValidBST(root1) == true);

    // Test case 2: False example
    TreeNode* root2 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
    assert(solution.isValidBST(root2) == false);

    // Test case 3: Single node tree
    TreeNode* root3 = new TreeNode(1);
    assert(solution.isValidBST(root3) == true);

    // Test case 4: False due to equal child
    TreeNode* root4 = new TreeNode(2, new TreeNode(2), nullptr);
    assert(solution.isValidBST(root4) == false);

    // Test case 5: Larger true example
    TreeNode* root5 = new TreeNode(10, new TreeNode(5), new TreeNode(15, new TreeNode(11), new TreeNode(20)));
    assert(solution.isValidBST(root5) == true);

    // Test case 6: False due to invalid subtree
    TreeNode* root6 = new TreeNode(10, new TreeNode(5, new TreeNode(1), new TreeNode(25)), new TreeNode(15));
    assert(solution.isValidBST(root6) == false);

    std::cout << "\033[32mAll tests passed!\033[0m\n";

    // Clean up dynamic memory
    delete root1->left;
    delete root1->right;
    delete root1;
    delete root2->left;
    delete root2->right->left;
    delete root2->right->right;
    delete root2->right;
    delete root2;
    delete root3;
    delete root4->left;
    delete root4;
    delete root5->left;
    delete root5->right->left;
    delete root5->right->right;
    delete root5->right;
    delete root5;
    delete root6->left->left;
    delete root6->left->right;
    delete root6->left;
    delete root6;
    
    return 0;
}