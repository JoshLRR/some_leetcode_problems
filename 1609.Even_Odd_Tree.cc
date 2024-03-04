#include <iostream>
#include <cassert>
#include <queue>

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
    bool isEvenOddTree(TreeNode* root) {
        std::queue<TreeNode*> nodeQueue;
        int currLevel = 0;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int n = nodeQueue.size();
            int prevOddNode = INT_MAX;
            int prevEvenNode = INT_MIN;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if (currLevel % 2 == 1) {                                   // Odd Level Case
                    if (node->val % 2 == 0 && node->val < prevOddNode) {
                        prevOddNode = node->val;
                    } else {
                        return false;
                    }
                } else {                                                    // Even Level Case
                    if (node->val % 2 == 1 && node->val > prevEvenNode) {
                        prevEvenNode = node->val;
                    } else {
                        return false;
                    }
                }
                if (node->left != nullptr) {
                    nodeQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    nodeQueue.push(node->right);
                }
            }
            ++currLevel;
        }

        return true;
    }
};

/*
    Level-order traversal
    Keep track of level
    If level is even, all nodes are odd and increase in value left to right
    If level is odd, all nodes are even and decrease in value left to right
*/

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(12);
    root->left->left->right = new TreeNode(8);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->left->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(2);

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->right->left = new TreeNode(7);

    TreeNode* root3 = new TreeNode(5);
    root3->left = new TreeNode(9);
    root3->right = new TreeNode(1);
    root3->left->left = new TreeNode(3);
    root3->left->right = new TreeNode(5);
    root3->right->left = new TreeNode(7);

    assert(solution.isEvenOddTree(root) == true);
    assert(solution.isEvenOddTree(root2) == false);
    assert(solution.isEvenOddTree(root3) == false);

    std::cout << "All tests passed!";
    return 0;
}