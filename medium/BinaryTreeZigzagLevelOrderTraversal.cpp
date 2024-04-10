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
    void dfs(const TreeNode* node, int level, std::vector<std::vector<int>>& levels)
    {
        if (!node)
            return;

        if (levels.size() == level) // [[1],[2,3],[4,5]] - при переходе слева направо может срезать с levels.size() == 3 до levels.size() == 2
            levels.resize(level + 1);

        levels[level].push_back(node->val);
        dfs(node->left, level + 1, levels);
        dfs(node->right, level + 1, levels);
    }

    // dfs
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> levels;
        dfs(root, 0, levels);
        for (int i = 0, I = (int)levels.size(); i < I; ++i)
        {
            if (i % 2 != 0)
                std::reverse(levels[i].begin(), levels[i].end());
        }
        
        return levels;
    }
#endif
#if 0
    // bfs
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (!root)
            return {};

        std::vector<std::vector<int>> levels;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            std::vector<int> level;
            for (int i = 0, I = q.size(); i < I; ++i)
            {
                TreeNode* node = q.front();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }

            levels.push_back(level);
        }

        for (int i = 0, I = (int)levels.size(); i < I; ++i)
        {
            if (i % 2 != 0)
                std::reverse(levels[i].begin(), levels[i].end());
        }

        return levels;
    }
#endif
};
