/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <deque>

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if (root == nullptr) return vector<vector<int>>();

        vector<vector<int>> results(1);

        std::deque<std::pair<TreeNode*, int>> q; // value, level
        q.emplace_back(root, 0);

        while(!q.empty()) {
            std::pair<TreeNode*, int> pair = q.front();
            q.pop_front();

            TreeNode* node = pair.first;
            int level = pair.second;
            if (level >= results.size())
                results.resize(level + 1);
            results[level].push_back(node->val);

            if (node->left)
                q.emplace_back(node->left, level + 1);
            if (node->right)
                q.emplace_back(node->right, level + 1);
        }

        std::reverse(results.begin(), results.end());
        return results;
    }
};