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
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> nodeQueue;
        int furthestLeft = 0;

        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            int n = nodeQueue.size();

            for (int i = 0; i < n; ++i) {
                TreeNode* node = nodeQueue.front();
                if (i == 0) furthestLeft = node->val;
                // std::cout << "Left value of new row: " << furthestLeft << "\n";
                std::cout << node->val << " ";

                nodeQueue.pop();
                if (node->left != nullptr) {
                    nodeQueue.push(node->left);
                }

                if (node->right != nullptr) {
                    nodeQueue.push(node->right);
                }
            }            
        }
        std::cout << "\n";

        return furthestLeft;
    }
};

/*
    Traverse tree using preorder traversal
    Keep track of deepest level seen so far, keep values of nodes at the deepest level so far in a set
    If a new deeper level is found, clear deepest set

    or

    Using inorder traversal -- first node output is the furthest left and deepest, node seen after the root is furthest left on the right-side 
    Determine height of these nodes, return the value of the node that's deeper

    jk I'm dumb, BFS is the way to go
*/

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    root2->right->left = new TreeNode(5);
    root2->right->left->left = new TreeNode(7);

    assert(solution.findBottomLeftValue(root) == 1);
    assert(solution.findBottomLeftValue(root2) == 7);

    std::cout << "All tests passed!";
    return 0;
}