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

    bool check(const TreeNode* left, const TreeNode* right)
    {
        if ((left == nullptr) && (right == nullptr))
            return true;
        else if ((left == nullptr) || (right == nullptr))
            return false;
        if (left->val != right->val)
            return false;

        return check(left->left, right->right) && check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return false;

        return check(root->left, root->right);
    }
};
