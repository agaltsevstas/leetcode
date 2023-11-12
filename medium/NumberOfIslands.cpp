// Time: O(m * n)
// Memory: O(m * n)

class Solution
{
    const std::list<std::function<bool(std::pair<int, int>&)>> _operations =
    {
        {[this](auto &pair) { return --pair.first >= 0;}}, // Up
        {[this](auto &pair) { return ++pair.first < I;}}, // Down
        {[this](auto &pair) { return --pair.second >= 0;}}, // Left
        {[this](auto &pair) { return ++pair.second < J;}}, // Right
    };
    
public:
    void bfs(const int i, const int j, std::vector<std::vector<bool>>& visited, std::vector<std::vector<char>>& grid)
    {
        std::deque<std::pair<int, int>> queue;
        queue.push_back(std::pair(i, j));
        visited[i][j] = true;

        while (!queue.empty())
        {
            for (auto& operation : _operations)
            {
                std::pair step = {queue.front().first, queue.front().second};

                if (!operation(step) || grid[step.first][step.second] == '0' || visited[step.first][step.second])
                    continue;
                
                visited[step.first][step.second] = true;
                queue.emplace_back(step.first, step.second);
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
