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
    void bfs(const int i, const int j, std::vector<std::vector<bool>>& visited, std::vector<std::vector<char>>& grid)
    {
        std::deque<std::pair<int, int>> queue;
        queue.push_back(std::pair(i, j));
        visited[i][j] = true;

        while (!queue.empty())
        {
            for (auto& step : steps)
            {
                auto q = queue.front();

                if (!step(q) || grid[q.first][q.second] == '0' || visited[q.first][q.second])
                    continue;
                
                visited[q.first][q.second] = true;
                queue.emplace_back(q.first, q.second);
            }
            
            queue.pop_front();
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid)
    {
        I = (int)grid.size();
        J = (int)grid.front().size();

        int result = 0;
        std::vector<std::vector<bool>> visited(I, std::vector<bool>(J, false));
        for (int i = 0; i < I; ++i)
        {
            for (int j = 0; j < J; ++j)
            {
                if (grid[i][j] == '0' || visited[i][j] == true)
                    continue;

                bfs(i, j, visited, grid);
                ++result;
            }
        }

        return result;
    }
    
private:
    int I = 0;
    int J = 0;
};
