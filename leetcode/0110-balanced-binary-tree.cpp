// 110. Balanced Binary Tree
// Binary Tree
#include <cmath>
#include <iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int max(int a, int b) { return (a > b) ? a : b; }

class Solution {
public:

    int getHeight(TreeNode* node, bool* balanced) {

        if (!node) return 0;
        if (!balanced) return 0;

        int leftHeight = getHeight(node->left, balanced);
        int rightHeight = getHeight(node->right, balanced);

        if (abs(leftHeight - rightHeight) > 1)
            *balanced = false;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {

        bool balanced = true;
        int height = getHeight(root, &balanced);

        return balanced;
    }
};

int main() {
    TreeNode root(1, 
        new TreeNode(2,
            new TreeNode(3, 
                new TreeNode(4),
                new TreeNode(4)),
            new TreeNode(3)),
        new TreeNode(2));

    Solution sln;
    std::cout << sln.isBalanced(&root);

    return 0;
}