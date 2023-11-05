// Time: O(n * m)
// Memory: O(n * m)

/*
    0, 0, 0, 0, 0, 0, 0, 0
    0, 1, 1, 1, 1, 1, 1, 1
    0, 1, 2, 3, 4, 5, 6, 7
    0, 1, 3, 6, 10, 15, 21, 28
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        const int M = m + 1;
        const int N = n + 1;
        std::vector<std::vector<int>> chess(M, std::vector<int>(N, 0));
        chess[1][1] = 1;

        for (int i = 1; i < M; ++i)
        {
            for (int j = 1; j < N; ++j)
            {
                if (i == 1 && j == 1)
                    continue;

                chess[i][j] = chess[i - 1][j] + chess[i][j - 1];
            }
        }

        return chess.back().back();
    }
};
