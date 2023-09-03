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

    bool isLeaf(const TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    bool hasSum(const TreeNode* node, int sum, int targetSum)
    {
        if (node == nullptr)
            return false;
            
        sum += node->val;

        if (bool leaf = isLeaf(node))
        {
            if (sum == targetSum)
                return true;
            else
            {
                sum = 0;
                return false;
            }
        }

        return hasSum(node->left, sum, targetSum) || hasSum(node->right, sum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasSum(root, 0, targetSum);
    }
};
