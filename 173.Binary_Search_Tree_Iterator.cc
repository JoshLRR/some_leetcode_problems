#include <iostream>
#include <cassert>
/*
Follow up:

    Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?

    Using a stack gets us to O(h) memory and O(1) time for hasNext(), but next() is still O(h) time, so I'm gonna be lazy and not write it.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};  

class BSTIterator {
private:
    std::vector<TreeNode*> nodes;
    int currIndex = -1;
public:
    void addNode(std::vector<TreeNode*>& nodes, TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        addNode(nodes, node->left);
        nodes.push_back(node);
        addNode(nodes, node->right);
    }
    BSTIterator(TreeNode* root) {
        addNode(nodes, root);
    }
    
    int next() {
        if (nodes[currIndex+1] != nullptr) {
            ++currIndex;
        }
        return nodes[currIndex]->val;
    }
    
    bool hasNext() {
        if (currIndex == nodes.size() - 1) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* bSTIterator = new BSTIterator(root);
    assert(bSTIterator->next() == 3);    // return 3
    assert(bSTIterator->next() == 7);    // return 7
    assert(bSTIterator->hasNext() == true); // return True
    assert(bSTIterator->next() == 9);    // return 9
    assert(bSTIterator->hasNext() == true); // return True
    assert(bSTIterator->next() == 15);    // return 15
    assert(bSTIterator->hasNext() == true); // return True
    assert(bSTIterator->next() == 20);    // return 20
    assert(bSTIterator->hasNext() == false); // return False

    std::cout << "All tests passed!";
    return 0;
}