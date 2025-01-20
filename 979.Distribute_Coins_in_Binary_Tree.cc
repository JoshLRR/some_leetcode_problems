#include <iostream>
#include <cassert>
#include <vector>
#include <chrono>


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
    int dfs(TreeNode* node, int& coinMoves) {
        if (!node) return 0;

        int left = dfs(node->left, coinMoves);
        int right = dfs(node->right, coinMoves);
        coinMoves += std::abs(left) + std::abs(right);

        return node->val + left + right - 1;
    }
    int distributeCoins(TreeNode* root) {
        int coinMoves = 0;
        dfs(root, coinMoves);

        return coinMoves;
    }
};

/*

*/

void deleteTree(TreeNode* node) {
    if (node == nullptr) return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

int main() {
    Solution solution;
    TreeNode* node1 = new TreeNode(3, new TreeNode(0), new TreeNode(0));
    TreeNode* node2 = new TreeNode(0, new TreeNode(3), new TreeNode(0));
    int ans1 = 2;
    int ans2 = 3;
    auto t0 = std::chrono::high_resolution_clock::now();
    assert(solution.distributeCoins(node1) == ans1);
    assert(solution.distributeCoins(node2) == ans2);
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - t0);
    double time = elapsed.count() / 1e6;

    deleteTree(node1);
    deleteTree(node2);

    std::cout << "\033[32m"
              << "All tests passed in " << time << "ms!\n"
              << "\033[0m";

    return 0;
}