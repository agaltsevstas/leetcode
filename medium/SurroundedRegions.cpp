// Time: O(m * n)
// Memory: O(m * n)

class Solution
{
    const std::list<std::function<bool(std::pair<int, int>&)>> steps =
    {
        {[this](auto& pair){ return --pair.first >= 0; }}, // вверх
        {[this](auto& pair){ return ++pair.first < I;  }}, // вниз
        {[this](auto& pair){ return --pair.second >= 0; }}, // влево
        {[this](auto& pair){ return ++pair.second < J; }} // вправо
    };

    void bfs(const int i, const int j, std::vector<std::vector<bool>>& visited, std::vector<std::vector<char>>& board)
    {
        visited[i][j] = true;
        std::vector<std::pair<int ,int>> queue;
        queue.emplace_back(i, j);

        bool isIsland = true;
        for (int q = 0; q < (int)queue.size(); ++q)
        {
            for (const auto& step : steps)
            {
                auto pair = queue[q];
                if (!step(pair))
                {
                    isIsland = false;
                    continue;
                }

                if (board[pair.first][pair.second] == 'X' || visited[pair.first][pair.second])
                    continue;

                visited[pair.first][pair.second] = true;
                queue.emplace_back(pair.first, pair.second);
            }
        }

        if (isIsland)
        {
            for (const auto& [ii, jj] : queue)
                board[ii][jj] = 'X';
        }
    }

public:
    void solve(std::vector<std::vector<char>>& board)
    {
        I = (int)board.size();
        J = (int)board.front().size();

        std::vector<std::vector<bool>> visited(I, std::vector<bool>(J, false));
        for (int i = 0; i < I; ++i)
        {
            for (int j = 0; j < J; ++j)
            {
                if (board[i][j] == 'X' || visited[i][j])
                    continue;

                bfs(i, j, visited, board);
            }
        }
    }

private:
    int I = 0;
    int J = 0;
};
