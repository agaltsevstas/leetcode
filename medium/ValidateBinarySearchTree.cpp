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
class Solution {
public:
    bool dfs(TreeNode* node, long min, long max)
    {
        if (!node)
            return true;
        else if (node->val <= min || node->val >= max)
            return false;

        return dfs(node->left, min, node->val) && dfs(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root)
    {
        if (!root)
            return false;
            
        // Если будет int, то будет валиться на примере [-2147483648,null,2147483647]
        long min = std::numeric_limits<long>::min();
        long max = std::numeric_limits<long>::max();

        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
};
