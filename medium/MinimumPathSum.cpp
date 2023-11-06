// Time: O(m * n)
// Memory: O(m * n)

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        auto M = grid.size() + 1;
        auto N = grid.front().size() + 1;

        std::vector<std::vector<int>> mas(M, std::vector<int>(N, std::numeric_limits<int>::max()));
        mas[1][1] = grid[0][0];

        for (decltype(M) i = 1; i < M; ++i)
        {
            for (decltype(N) j = 1; j < N; ++j)
            {
                if (i == 1 && j == 1)
                    continue;

                mas[i][j] = std::min(mas[i - 1][j], mas[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return mas.back().back();
    }
};
