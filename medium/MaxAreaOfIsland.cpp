// Time: O(m * n)
// Memory: O(m * n)

class Solution
{
    const std::array<std::function<bool(std::pair<int, int>&)>, 4> steps
    {
        [this](auto& step) { return --step.first >= 0; },
        [this](auto& step) { return ++step.first < I;  },
        [this](auto& step) { return --step.second >= 0; },
        [this](auto& step) { return ++step.second < J; }
    };

public:

    int bfs(const int i, const int j, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& grid)
    {
        std::deque<std::pair<int, int>> queue = {{i, j}};
        visited[i][j] = true;

        int result = 1;
        while (!queue.empty())
        {
            for (const auto& step: steps)
            {
                auto q = queue.front();
                if (!step(q) || grid[q.first][q.second] == 0 || visited[q.first][q.second])
                    continue;

                ++result;
                queue.emplace_back(q);
                visited[q.first][q.second] = true;
            }

            queue.pop_front();
        }

        return result;
    }

    int dfs(const int i, const int j, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& grid)
    {
        visited[i][j] = true;
        int result = 1;

        for (const auto& step: steps)
        {
            auto q = std::make_pair(i, j);
            if (!step(q) || grid[q.first][q.second] == 0 || visited[q.first][q.second])
                continue;

            result += dfs(q.first, q.second, visited, grid);
        }

        return result;
    }

    int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
    {
        I = (int)grid.size();
        J = (int)grid.front().size();
        std::vector<std::vector<bool>> visited(I, std::vector<bool>(J, false));
        int result = 0;

        for (int i = 0; i < I; ++i)
        {
            for (int j = 0; j < J; ++j)
            {
                if (grid[i][j] == 0 || visited[i][j])
                    continue;

                // result = std::max(bfs(i, j, visited, grid), result); // bfs
                result = std::max(dfs(i, j, visited, grid), result); // dfs (быстрее, чем bfs)
            }
        }
        return result;
    }

private:
    int I = 0;
    int J = 0;
};
