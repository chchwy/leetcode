/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 找出二元樹的高度 
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        
        if ( root == NULL )
            return 0;
            
        int leftDepth = maxDepth( root->left );
        int rightDepth = maxDepth( root->right );
        
        return 1 + std::max( leftDepth, rightDepth );
    }
};