// Time: O(logn)
// Memory: O(1)

/*
height = 3
width = 4
target = 3

1, 3, 5, 7,  left = 0, right = 11, mid = 5, col = 1, row = 1, number = 11
10,11,16,20, left = 0, right = 4, mid = 2, col = 2, row = 0, number = 5
23,30,34,60  left = 0, right = 1, mid = 0, col = 0, row = 0, number = 1
             left = 1, right = 1, mid = 1, col = 1, row = 0, number = 3
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int height = (int)matrix.size();
        int width = (int)matrix[0].size();

        int left = 0;
        int right = height * width - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            // Раскладываем весь массив в строку, поэтому row = mid / width, а col = mid % width
            int row = mid / width;
            int col = mid % width;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return false;
    }
};
