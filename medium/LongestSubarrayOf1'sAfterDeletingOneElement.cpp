// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        auto size = nums.size();
        if (size <= 1)
            return size - 1;

        int zero_count = 0, max = 0;
        for (int i = 0, j = 0; i < size; ++i)
        {
            if (nums[i] == 0)
                ++zero_count;

            if (zero_count > 1)
            {
                max = std::max(max, i - j - 1);
                while (nums[j] != 0)
                {
                    ++j;
                }

                ++j;
                --zero_count;
            }
            else
            {
                max = std::max(max, i - j);
            }
        }

        return max;
    }
};
