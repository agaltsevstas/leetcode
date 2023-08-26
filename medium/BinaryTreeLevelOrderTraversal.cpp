/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    vector<vector<int>> preOrder(TreeNode* root, int level, vector<vector<int>>& levels)
    {
        if (root == nullptr)
            return levels;

        if (level == levels.size())
            levels.push_back({});

        levels[level].emplace_back(root->val);
        preOrder(root->left, level + 1, levels);
        preOrder(root->right, level + 1, levels);
        return levels;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        return preOrder(root, 0, levels);
    }
};
