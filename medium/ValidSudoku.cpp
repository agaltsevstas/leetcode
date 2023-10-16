// Time: O(n^2)
// Memory: O(n^2)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        auto hash = [](const std::pair<int, int>& pair) // хэш для pair!
        {
            std::size_t h1 = std::hash<decltype(pair.first)>()(pair.first);
            std::size_t h2 = std::hash<decltype(pair.second)>()(pair.second);
 
            return h1 ^ h2;
        };

        std::unordered_set<std::pair<int, int>, decltype(hash)> rows;
        std::unordered_set<std::pair<int, int>, decltype(hash)> cols;
        std::unordered_set<std::pair<int, int>, decltype(hash)> blocks;

        for (int row = 0, ROW = (int)board.size(); row < ROW; ++row)
        {
            for (int col = 0, COL = (int)board[row].size(); col < COL; ++col)
            {
                if (board[row][col] == '.')
                {
                    continue;
                }

                if (cols.find({board[row][col], col}) != cols.end())
                {
                    return false;
                }
                else
                {
                    cols.insert({board[row][col], col});
                }

                if (rows.find({board[row][col], row}) != rows.end())
                {
                    return false;
                }
                else
                {
                    rows.insert({board[row][col], row});
                }

                int block = row / 3 * 3 + col / 3;
                if (blocks.find({board[row][col], block}) != blocks.end())
                {
                    return false;
                }
                else
                {
                    blocks.insert({board[row][col], block});
                }
            }
        }

        return true;
    }
};
