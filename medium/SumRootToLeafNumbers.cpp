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

// Time: O(n)
// Memory: O(h), где h - высота дерева. В худшем случае h = n
class Solution
{
public:
    int sumNumbers(TreeNode* root, int sum = 0)
    {
        if (!root)
            return 0;

        sum = sum * 10 + root->val;
        if (!root->left && !root->right)
            return sum;

        int left_sum = sumNumbers(root->left, sum);
        int right_sum = sumNumbers(root->right, sum);

        return left_sum + right_sum;
    }
};
