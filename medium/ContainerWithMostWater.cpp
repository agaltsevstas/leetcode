// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int first_index = 0;
        int last_index = height.size() - 1;
        int max = 0;

        while (first_index < last_index)
        {
            auto difference = last_index - first_index;
            auto min_height = std::min(height[last_index], height[first_index]);
            auto square = difference * min_height;
            max = std::max(square, max);
            if (height[first_index] <= height[last_index])
            {
                ++first_index;
            }
            else
            {
                --last_index;
            }
        }

        return max;
    }
};
