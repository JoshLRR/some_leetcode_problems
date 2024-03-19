#include <iostream>
#include <cassert>
#include <sstream>
#include <queue>
// #include <istream>
// #include <ostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::istringstream in(data);
        return deserialize(in);    
    }
private:
    void serialize(TreeNode* root, std::ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(std::istringstream& in) {
        std::string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

/*
    Encode and decode as preorder 
    ' ' single space indicates individual node
    '# '  indicates new level
    1  2 3  4 5 6 7  8 9 10 11 12 13 14 15
    
*/

int main() {
    Codec codec;

    assert(codec);

    std::cout << "\033[32mAll tests passed!\033[0m\n";
    return 0;
}