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

    void preOrder(const TreeNode* root, int level, vector<vector<int>>& levels)
    {
        if (root == nullptr)
            return;

        if (level == levels.size())
            levels.push_back({});

        levels[level].emplace_back(root->val);
        preOrder(root->left, level + 1, levels);
        preOrder(root->right, level + 1, levels);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        preOrder(root, 0, levels);
        return levels;
    }
};
