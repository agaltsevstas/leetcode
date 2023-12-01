// Time: O(m * n)
// Memory: O(m * n)

class Solution
{
    const std::array<std::function<bool(std::pair<int, int>&)>, 4> steps =
    {
        [this](auto& pair){ return --pair.first >= 0; },
        [this](auto& pair){ return ++pair.first < I; },
        [this](auto& pair){ return --pair.second >= 0; },
        [this](auto& pair){ return ++pair.second < J; }
    };

    int bfs(const int i, const int j, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& grid)
    {
        visited[i][j] = true;
        std::deque<std::pair<int, int>> queue = {{i, j}};

        int result = 0;
        while (!queue.empty())
        {
            int curResult = 4;
            for (const auto& step: steps)
            {
                auto q = queue.front();
                if (!step(q) || grid[q.first][q.second] == 0)
                    continue;
                
                --curResult;
                if (visited[q.first][q.second])
                    continue;

                visited[q.first][q.second] = true;
                queue.emplace_back(q);
            }

            queue.pop_front();
            result += curResult;
        }

        return result;
    }

public:
    int islandPerimeter(std::vector<std::vector<int>>& grid)
    {
        I = (int)grid.size();
        J = (int)grid.front().size();
        std::vector<std::vector<bool>> visited(I, std::vector<bool>(J, false));

        for (int i = 0; i < I; ++i)
        {
            for (int j = 0; j < J; ++j)
            {
                if (grid[i][j] == 0 || visited[i][j])
                    continue;

                return bfs(i, j, visited, grid);
            }
        }

        return 0;
    }

private:
    int I = 0;
    int J = 0;
};
