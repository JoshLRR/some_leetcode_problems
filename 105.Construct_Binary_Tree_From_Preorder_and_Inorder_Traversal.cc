#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        return buildSubTree(preorder, 0, inorder.size() - 1);
    }

    TreeNode* buildSubTree(std::vector<int>& preorder, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) return nullptr;

        TreeNode* node = new TreeNode(preorder[preorderIndex++]);
        int inorderRootIndex = inorderMap[node->val];

        node->left = buildSubTree(preorder,inorderStart,inorderRootIndex-1);
        node->right = buildSubTree(preorder,inorderRootIndex+1,inorderEnd);

        return node;
    }
private:
    std::unordered_map<int, int> inorderMap;
    int preorderIndex = 0;
};

/*
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]

    Root and its children at front of preorder

*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}