// Time: O(logn)
// Memory: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int height = (int)matrix.size();
        int width = (int)matrix[0].size();

        int left = 0;
        int right = height * width;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            int row = mid / width;
            int col = mid % width;
            if (matrix[row][col] > target)
            {
                right = mid;
            }
            else if (matrix[row][col] < target)
            {
                left = mid;
            }
            else
            {
                return true;
            }
        }

        int row = left / width;
        int col = left % width;

        return matrix[row][col] == target ? true : false;
    }
};
