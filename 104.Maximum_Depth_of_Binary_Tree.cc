#include <iostream>
#include <cassert>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return (std::max(maxDepth(root->left), maxDepth(root->right)) + 1);
    }
};

/*
    0
   / \
  1   2

  std::max(root->left, root->right)  on 1 results in 0 since it has no children, add 1 and returns up
  node 0 now has a max of (1,1) to pick from which is 1, add 1 for its own level 
  returns 2
*/

int main() {
    Solution solution;

    assert(solution);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}