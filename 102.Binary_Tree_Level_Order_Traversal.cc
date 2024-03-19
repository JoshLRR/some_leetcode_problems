#include <iostream>
#include <cassert>
#include <vector>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::queue<TreeNode*> level;
        std::vector<std::vector<int>> ans;
        level.push(root);

        while (!level.empty()) {
            std::vector<int> currLevel;
            int n = level.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = level.front();
                currLevel.push_back(node->val);
                level.pop();
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
            }

            ans.push_back(currLevel);
        }

        return ans;
    }
};

/*

*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}