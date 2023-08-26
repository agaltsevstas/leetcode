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
    void preOrder(const TreeNode* root, int level, vector<int>& result)
        {
            if (root == nullptr)
                return;

            if (level == result.size())
                result.push_back(0);

            result[level] = root->val;
            preOrder(root->left, level + 1, result);
            preOrder(root->right, level + 1, result);
        }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        preOrder(root, 0, result);
        return result;
    }
};
