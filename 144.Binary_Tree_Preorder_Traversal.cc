#include <iostream>
#include <cassert>
#include <functional>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive Solution
// class Solution {
// public:
//     std::vector<int> preorderTraversal(TreeNode* root) {
//         std::vector<int> ans;
//         std::function<void(TreeNode*)> dfs = [&](TreeNode* node) -> void {
//             if (node == nullptr) return;

//             ans.push_back(node->val);
//             dfs(node->left);
//             dfs(node->right);
//         };

//         dfs(root);
//         return ans;
//     }
// };

// Iterative Solution -- using stack, not as efficient as Morris traversal
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        std::stack<TreeNode*> nums;
        if (root == NULL) return {};
        
        nums.push(root);
        while (!nums.empty()) {
            TreeNode* temp = nums.top();
            nums.pop();
            ans.push_back(temp->val);
            if (temp->right) nums.push(temp->right);
            if (temp->left) nums.push(temp->left);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    std::vector<int> ans1 = {1, 2, 3};

    TreeNode* root2 = nullptr;
    std::vector<int> ans2 = {};
    TreeNode* root3 = new TreeNode(1);
    std::vector<int> ans3 = {1};

    assert(solution.preorderTraversal(root1) == ans1);
    assert(solution.preorderTraversal(root2) == ans2);
    assert(solution.preorderTraversal(root3) == ans3);

    std::cout << "All tests passed!";
    return 0;
}