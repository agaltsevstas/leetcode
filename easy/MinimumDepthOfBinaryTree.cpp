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

    int findMinDepth(TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        if (isLeaf(node))
            return 1;

        int minimum = std::numeric_limits<int>::max();
        if (node->left)
            minimum = std::min(minimum, minDepth(node->left) + 1);
        if (node->right)
            minimum = std::min(minimum, minDepth(node->right) + 1);

        return minimum;
    }

    int minDepth(TreeNode* root) {
        return findMinDepth(root);
    }
};
