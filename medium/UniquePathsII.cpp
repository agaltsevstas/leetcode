// Time: (n * m)
// Memory: (n * m)

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
    {
        if (obstacleGrid.front().front() == 1)
            return 0;

        const int N = (int)obstacleGrid.size() + 1;
        const int M = (int)obstacleGrid.front().size() + 1;

        std::vector<std::vector<int>> chess(N, std::vector<int>(M, 0));
        chess[1][1] = 1;
        for (int i = 1; i < N; ++i)
        {
            for (int j = 1; j < M; ++j)
            {
                if (i == 1 && j == 1)
                    continue;

                if (obstacleGrid[i - 1][j - 1] == 1)
                {
                    chess[i][j] = 0;
                    continue;
                }

                chess[i][j] = chess[i - 1][j] + chess[i][j - 1];
            }
        }

        return chess.back().back();
    }
};
