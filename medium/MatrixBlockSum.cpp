// Time: O(n * m)
// Memory: O(n * m)

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size() + 1;
        int columns = mat[0].size() + 1;

        vector<vector<int>> prefix_mas;
        prefix_mas.resize(rows);
        prefix_mas[0] = std::vector<int>(columns, 0);

        for (decltype(columns) i = 1; i < rows; ++i)
        {
            prefix_mas[i].resize(columns);
            prefix_mas[i][0] = 0;
        }

        for (decltype(rows) i = 1; i < rows; ++i)
        {
            for (decltype(columns) j = 1; j < columns; ++j)
            {
                auto sum = prefix_mas[i][j - 1] + prefix_mas[i - 1][j] - prefix_mas[i - 1][j - 1];
                prefix_mas[i][j] = sum + mat[i - 1][j - 1];
            }
        }

        auto result = mat;
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < columns; ++j)
            {
                /// Условия выхода за границу матрицы
                int row1 = std::max(0, i - (k + 1)); // Выход за верхнюю границу
                int col1 = std::max(0, j - (k + 1)); // Выход за левую границу
                int row2 = std::min(rows - 1, i + k); // Выход за нижнюю границу
                int col2 = std::min(columns - 1, j + k); // Выход за правую границу

                result[i - 1][j - 1] = prefix_mas[row2][col2] - prefix_mas[row1][col2] - prefix_mas[row2][col1] + prefix_mas[row1][col1];
            }
        }

        return result;
    }
};
