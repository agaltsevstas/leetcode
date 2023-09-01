class NumMatrix {
public:
    // Time: O(rows * columns)
    // Memory: O(rows * columns)
    NumMatrix(vector<vector<int>>& matrix) {
        auto rows = matrix.size() + 1;
        auto columns = matrix[0].size() + 1;

        _prefix_mas.resize(rows);
        _prefix_mas[0] = std::vector<int>(columns, 0);

        for (decltype(columns) i = 1; i < rows; ++i)
        {
            _prefix_mas[i].resize(columns);
            _prefix_mas[i][0] = 0;
        }

        for (decltype(rows) i = 1; i < rows; ++i)
        {
            for (decltype(columns) j = 1; j < columns; ++j)
            {
                auto sum = _prefix_mas[i][j - 1] + _prefix_mas[i - 1][j] - _prefix_mas[i - 1][j - 1];
                _prefix_mas[i][j] = sum + matrix[i - 1][j - 1];
            }
        }
    }
    
    // Time: O(1)
    // Memory: O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2 += 1;
        col2 += 1;
        return _prefix_mas[row2][col2] - _prefix_mas[row1][col2] - _prefix_mas[row2][col1] + _prefix_mas[row1][col1];
    }

private:
    std::vector<std::vector<int>> _prefix_mas;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
