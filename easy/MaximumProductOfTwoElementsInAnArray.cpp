class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_index = 0;
        int max_elem = nums.front();
        for (size_t i = 1, I = nums.size(); i < I; ++i)
        {
            if (nums[i] > max_elem)
            {
                max_index = i;
                max_elem = nums[i];
            }
        }

        max_elem = 0;
        for (size_t i = 0, I = nums.size(); i < I; ++i)
        {
            if (nums[i] > max_elem && i != max_index)
                max_elem = nums[i];

            if (i == I - 1)
                return (max_elem - 1) * (nums[max_index] - 1);
        }

        return 0;
    }
};
