// Time: O(n)
// Memory: O(max(n + m)), где число n - число графов, m - число ребер

class Solution
{
public:
    bool dfs(const int course, std::vector<int>& colors, std::vector<std::vector<int>>& matrix)
    {
        if (colors[course] == 2)
            return true;
        else if (colors[course] == 1)
            return false;
        
        colors[course] = 1;
        for (const auto& number : matrix[course])
        {
            if (!dfs(number, colors, matrix))
                return false;
        }

        colors[course] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> matrix(numCourses);
        for (const auto& p : prerequisites)
            matrix[p.front()].emplace_back(p.back());

        std::vector<int> colors(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(i, colors, matrix))
                return false;
        }
        
        return true;
    }
};
