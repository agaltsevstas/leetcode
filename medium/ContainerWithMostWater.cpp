// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int first = 0;
        int last = (int)height.size() - 1;
        int max = 0;

        while (first < last)
        {
            int min = std::min(height[first], height[last]);
            int squere = min * (last - first);
            max = std::max(max, squere);
            if (height[first] >= height[last])
                --last;
            else
                ++first;
        }

        return max;
    }
};
