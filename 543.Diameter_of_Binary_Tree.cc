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
    int findNodeHeights(TreeNode* node, int& maxDiameter) {
        // Base case
        if (node == nullptr) return 0;
        // Recursive case

        int leftHeight = findNodeHeights(node->left, maxDiameter);
        int rightHeight = findNodeHeights(node->right, maxDiameter);

        int currentDiameter = leftHeight + rightHeight;
        maxDiameter = std::max(maxDiameter, currentDiameter);

        return 1 + std::max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        // std::cout << "node order: " << root->val << " ";
        findNodeHeights(root, maxDiameter);
        return maxDiameter;
    }
};

/*
    Iterate through each node using pre-order traversal
    For each node, find height of left and right sub-trees
    Compare to currently established max
*/

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    TreeNode* root3 = new TreeNode(2);
    root3->left = new TreeNode(3);
    root3->right = new TreeNode(1);

    assert(solution.diameterOfBinaryTree(root) == 3);
    assert(solution.diameterOfBinaryTree(root2) == 1);
    assert(solution.diameterOfBinaryTree(root3) == 2);


    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    delete root2->left;
    delete root2;

    std::cout << "All tests passed!";
    return 0;
}