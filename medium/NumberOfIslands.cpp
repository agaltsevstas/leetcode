// Time: O(m * n)
// Memory: O(m * n)

class Solution
{
    const std::array<std::function<bool(std::pair<int, int>&)>, 4> steps =
    {
        [this](auto& pair){ return --pair.first >= 0; }, // Up
        [this](auto& pair){ return ++pair.first < I; }, // Down
        [this](auto& pair){ return --pair.second >= 0; }, // Left
        [this](auto& pair){ return ++pair.second < J; } // Right
    };
private:
    int bfs(int i, int j, std::vector<std::vector<bool>>& used, std::vector<std::vector<char>>& grid)
    {
        std::queue<std::pair<int, int>> queue;
        queue.push({i, j});
        used[i][j] = true;

        while (!queue.empty())
        {
            for (auto& step: steps)
            {
                auto q = queue.front(); // На каждом шаге делаем копию, потому что step изменяет по ссылке

                if (step(q) && grid[q.first][q.second] == '1' && !used[q.first][q.second]) // step изменяет по ссылке
                {
                    queue.push(q); // копия уже изменена в step
                    used[q.first][q.second] = true;
                }
            }

            queue.pop();
        }

        return 1;
    }
public:

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int result = 0;
        I = (int)grid.size();
        J = (int)grid.front().size();
        std::vector<std::vector<bool>> used(I, std::vector<bool>(J, false));

        for (int i = 0; i < I; ++i)
        {
            for (int j = 0; j < J; ++j)
            {
                if (grid[i][j] == '1' && !used[i][j])
                    result += bfs(i, j, used, grid);
            }
        }

        return result;
    }

private:
    int I = 0;
    int J = 0;
};
