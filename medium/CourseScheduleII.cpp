// n - numCourses, а m - prerequisites.size()
// Time: O(max(n, m))
// Memory:  O(max(n, m))

class Solution
{
public:
    bool dfs(const int course, std::vector<int>& visited, const std::vector<std::vector<int>>& matrix, std::vector<int>& oResult)
    {
        if (visited[course] == 1)
            return false;
        else if (visited[course] == 2)
            return true;

        visited[course] = 1;
        for (const auto& number: matrix[course])
        {
            if (!dfs(number, visited, matrix, oResult))
                return false;
        }
        
        visited[course] = 2;
        oResult.emplace_back(course);
        return true;
    }

    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> matrix(numCourses);
        for (const auto& p : prerequisites)
            matrix[p.front()].emplace_back(p.back());

        std::vector<int> visited(numCourses, 0);
        std::vector<int> result;
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(i, visited, matrix, result))
                return {};
        }

        return result;
    }
};
