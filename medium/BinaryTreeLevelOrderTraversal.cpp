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

class Solution
{
public:
#if 1
    void preOrder(const TreeNode* node, int level, std::vector<std::vector<int>>& levels)
    {
        if (!node)
            return;

        if (levels.size() < level) // [[1],[2,3],[4,5]] - при переходе слева направо может срезать с levels.size() == 3 до levels.size() == 2
            levels.resize(level);

        levels[level - 1].push_back(node->val);

        preOrder(node->left, level + 1, levels);
        preOrder(node->right, level + 1, levels);
    }

    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> levels;
        preOrder(root, 1, levels);
        return levels;
    }
#endif
#if 0
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            std::vector<int> level;
            for (int i = 0, I = (int)q.size(); i < I; ++i) // size - статичен
            {
                TreeNode* node = q.front();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }

            result.push_back(level);
        }

        return result;
    }
#endif
};
