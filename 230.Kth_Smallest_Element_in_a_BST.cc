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
    void addToHeap(TreeNode* node, int& addedVals, int& k) {
        if (!node || addedVals == k) return;

        addToHeap(node->left, addedVals, k);
        nums.push(node->val);
        ++addedVals;
        addToHeap(node->right, addedVals, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // while (!minHeap.empty()) minHeap.pop();
        while (!nums.empty()) nums.pop();
        int addedVals = 0;
        // Add all node vals to minHeap
        addToHeap(root, addedVals, k);

        // while (!minHeap.empty()) {
        //     std::cout << minHeap.top() << ", ";
        //     minHeap.pop();
        // }

        // std::cout << "\n";

        for (int i = 0; i < k-1; ++i) {
            // std::cout << "Pooping: " << minHeap.top() << "\n";
            // minHeap.pop();
            nums.pop();
        }

        // std::cout << minHeap.top() << "\n";
        // std::cout << "======\n";
        // return minHeap.top();
        return nums.front();
    }
private:
    // std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::queue<int> nums;
};

/*
    Brute force
    Iterate through the tree and put all values into a priority queue
    Pop k-1 elements from the min heap and return the top

    -- Slightly optimized -- Use a queue and push only k nodes using inorder traversal
    Pop k-1 elements from the queue and return the front
*/

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4));
    int k1 = 1;
    int ans1 = 1;
    assert(solution.kthSmallest(root, k1) == ans1);

    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4));
    root2->right = new TreeNode(6);
    int k2 = 3;
    int ans2 = 3;
    assert(solution.kthSmallest(root2, k2) == ans2);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}