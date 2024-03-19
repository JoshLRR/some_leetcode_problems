#include <iostream>
#include <cassert>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// Brute force solution
class Solution {
public:
    bool isEqualToSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot) return root == nullptr && subRoot == nullptr;
        else if (root->val == subRoot->val) {
            return isEqualToSubtree(root->left, subRoot->left) && isEqualToSubtree(root->right, subRoot->right);
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        else if (isEqualToSubtree(root, subRoot)) return true;
        else return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};

// Optimized solution
// class Solution {
//     std::vector<TreeNode*> nodes;

// public:
//     bool isSubtree(TreeNode* s, TreeNode* t) {
//         if (!s && !t) return true;
//         if (!s || !t) return false;

//         getDepth(s, getDepth(t, -1));

//         for (TreeNode* n: nodes)
//             if (identical(n, t))
//                 return true;

//         return false;
//     }

//     int getDepth(TreeNode* r, int d) {
//         if (!r)
//             return -1;

//         int depth = std::max(getDepth(r->left, d), getDepth(r->right, d)) + 1;

//         // Check if depth equals required value
//         // Require depth is -1 for tree t (only return the depth, no push)
//         if (depth == d)
//             nodes.push_back(r);

//         return depth;
//     }

//     bool identical(TreeNode* a, TreeNode* b) {
//         if (!a && !b) return true;
//         if (!a || !b || a->val != b->val) return false;

//         return identical(a->left, b->left) && identical(a->right, b->right);
//     }
// };

/*
    DFS
    For each node, could test to see if it's the subroot -- BRUTE FORCE
        But with subroot being up to 1000 nodes, this could be very time intensive
            O(n * m) -- n is num of nodes and m is size of subtree to be searched

    An optimized solution can be reached by checking nodes that have the same max depth as subRoot
    First, get max depth of subRoot then recursively check each node in root.
    If the depth is equal, push to a vector and compare with each node in the vector with subRoot
*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}