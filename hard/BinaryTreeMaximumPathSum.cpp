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
    int postOrder(TreeNode* root, int& max)
    {
        if (!root)
            return 0; // Для одного корня: [-3] при сложении 0 + 0 -3 = -3

        int left_max = std::max(postOrder(root->left, max), 0); // Обнуляем для отрицательных чисeл: [2,-1]
        int right_max = std::max(postOrder(root->right, max), 0); // // Обнуляем для отрицательных чисeл [2,-1]
        int new_max = left_max + right_max + root->val; // сложение всех узлов

        max = std::max(max, new_max); // Обновляем новый макс
        return root->val + std::max(left_max, right_max); // можно пойти в левый или в правый, одновременно пойти в обе стороны нельзя!
    }

    // dfs
    int maxPathSum(TreeNode* root)
    {
        int max = -1001; // std::numeric_limits<int>::min() нельзя потому что будет переполнение
        postOrder(root, max);
        return max;
    }
};
