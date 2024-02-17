// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int trap(vector<int>& height)
    {
        // [0,1,0,2,1,0,1,3,2,1,2,1]
        int left = 0;
        int right = (int)height.size() - 1; // 11
        int max_left = 0;
        int max_right = 0;
        int result = 0;

        while (left < right) // Средний элемент не нужно считать
        {
            if (height[left] <= height[right]) // 0 <= 1, 1 <= 1, 0 <= 1, 2 <= 2, 1 <= 2, 0 <= 2, 1 <= 2, 3 > 2, 3 > 1, 3 > 2
            {
                if (height[left] > max_left) // 0 == 0, 1 > 0, 0 < 1, 2 > 1, 0 < 2, 1 < 2
                    max_left = height[left]; // 1, 2
                else
                    result += max_left - height[left]; // 0, 1, 2, 4, 5

                ++left; // 1, 2, 3, 4, 5, 6, 7
            }
            else
            {
                if (height[right] > max_right) // 1 > 0, 2 > 1, 1 < 2, 2 == 2
                    max_right = height[right]; // 1, 2
                else
                    result += max_right - height[right]; // 6

                --right; // 10, 9, 8
            }
        }

        return result;
    }
};
