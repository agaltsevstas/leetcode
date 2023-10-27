// Time: O(n^n)
// Memory: O(n*n)

class Solution
{
public:
    void backTracking(const int n,
                      int row,
                      std::vector<std::string>& queens,
                      std::vector<bool>& cols,
                      std::vector<bool>& rows,
                      std::vector<bool>& mainDiagonal,
                      std::vector<bool>& secondDiagonal,
                      std::vector<std::vector<std::string>>& oResult)
    {
        if (row == n)
        {
            oResult.emplace_back(queens);
            return;
        }
        
        int offset = n - 1;
        for (int col = 0; col < n; ++col)
        {
            if (cols[col] || rows[row] || mainDiagonal[row - col + offset] || secondDiagonal[row + col])
                continue;
            
            cols[col] = true;
            rows[row] = true;
            mainDiagonal[row - col + offset] = true;
            secondDiagonal[row + col] = true;
            queens[row][col] = 'Q';
            
            backTracking(n, row + 1, queens, cols, rows, mainDiagonal, secondDiagonal, oResult);
            
            cols[col] = false;
            rows[row] = false;
            mainDiagonal[row - col + offset] = false;
            secondDiagonal[row + col] = false;
            queens[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        std::vector<bool> cols(n, false), rows(n, false), mainDiagonal(2 * n - 1, false), secondDiagonal(2 * n - 1, false);
        std::vector<std::string> queens(n, std::string(n, '.'));
        std::vector<std::vector<std::string>> result;
        backTracking(n, 0, queens, cols, rows, mainDiagonal, secondDiagonal, result);
        return result;
    }
};
