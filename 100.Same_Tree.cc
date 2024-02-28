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
    bool dfs(TreeNode* pNode, TreeNode* qNode) {
        if (pNode == nullptr && qNode == nullptr) return true;
        if (pNode == nullptr || qNode == nullptr || pNode->val != qNode->val) return false;
        
        std::cout << "p val: " << pNode->val << " -- " << "q node: " << qNode->val << "\n";

        return (dfs(pNode->left, qNode->left) && dfs(pNode->right, qNode->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};

int main() {
    Solution solution;
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);
    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    assert(solution.isSameTree(p, q));
    assert(solution.isSameTree(p2, q2) == false);

    std::cout << "All tests passed!";

    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    delete p2->left;
    delete p2;
    delete q2->right;
    delete q2;

    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
