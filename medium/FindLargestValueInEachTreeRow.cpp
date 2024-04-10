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
#if 1
    void dfs(TreeNode* node, int level, std::vector<int>& result)
    {
        if (!node)
            return;

        if (result.size() == level)
            result.push_back(node->val);
        else
            result[level] = std::max(result[level], node->val);

        dfs(node->left, level + 1, result);
        dfs(node->right, level + 1, result);
    }

    // dfs
    std::vector<int> largestValues(TreeNode* root)
    {
        std::vector<int> result;
        dfs(root, 0, result);
        return result;
    }
#endif
#if 0
    // bfs
    std::vector<int> largestValues(TreeNode* root)
    {
        if (!root)
            return {};

        std::vector<int> result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int max = std::numeric_limits<int>::min();
            for (int i = 0, I = (int)q.size(); i < I; ++i) // size - статичен
            {
                TreeNode* node = q.front();
                max = std::max(max, node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }

            result.push_back(max);
        }

        return result;
    }
#endif
};
