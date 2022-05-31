// 226. Invert Binary Tree
// Binary Tree

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void swap(TreeNode*& a, TreeNode*& b) {
        TreeNode* tmp = a;
        a = b;
        b = tmp;
    }

    TreeNode* invertTree(TreeNode* root) {

        if (!root) return nullptr;

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
