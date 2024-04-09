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
 // Memory: O(n)
class Solution {
public:

    void bfs(TreeNode* node, int level, std::vector<int>& result)
    {
        if (!node)
            return;

        if (result.size() == level)
            result.push_back(node->val);
        else
            result[level] = std::max(result[level], node->val);

        bfs(node->left, level + 1, result);
        bfs(node->right, level + 1, result);
    }

    std::vector<int> largestValues(TreeNode* root)
    {
        std::vector<int> result;
        bfs(root, 0, result);
        return result;
    }
};
