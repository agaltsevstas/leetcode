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
    void dfs(TreeNode* node, int level, uint64_t index, std::vector<std::vector<uint64_t>>& result) // uint64_t index - кол-во элементов может выходить за рамки int
    {
        if (!node)
            return;

        if (result.size() == level)
            result.resize(level + 1);

        result[level].push_back(index);

        dfs(node->left, level + 1, index * 2, result);
        dfs(node->right, level + 1, index * 2 + 1, result);
    }

    // dfs
    int widthOfBinaryTree(TreeNode* root)
    {
        std::vector<std::vector<uint64_t>> result;
        dfs(root, 0, 0, result);
        int width = std::numeric_limits<int>::min();
        for (auto it = result.rbegin(); it != result.rend(); ++it)
        {
            int difference = int(it->back() - it->front());
            width = std::max(width, difference);
        }

        return width + 1; // т.к отсчет начинался с 0
    }
#endif
#if 0
    // bfs
    int widthOfBinaryTree(TreeNode* root)
    {
        if (!root)
            return 1;

        std::vector<std::vector<uint64_t>> result;
        std::queue<std::pair<TreeNode*, uint64_t>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            std::vector<uint64_t> levels;
            for (int i = 0, I = (int)q.size(); i < I; ++i)
            {
                auto [node, index] = q.front();
                levels.push_back(index);
                if (node->left)
                    q.push({node->left, index * 2});
                if (node->right)
                    q.push({node->right, index * 2 + 1});
                q.pop();
            }

            result.push_back(levels);
        }

        int width = std::numeric_limits<int>::min();
        for (auto it = result.rbegin(); it != result.rend(); ++it)
        {
            int difference = int(it->back() - it->front());
            width = std::max(width, difference);
        }
        return width + 1; // т.к отсчет начинался с 0
    }
#endif
};
