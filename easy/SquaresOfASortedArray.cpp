// Time: O(n)
// Memory: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto size = nums.size();
        if (size < 1)
            return nums;

        int first_index = 0;
        int last_index = size - 1;
        int index_result = last_index;

        vector<int> result(size);
        while(first_index <= last_index)
        {
            auto first_abs = std::abs(nums[first_index]);
            auto last_abs = std::abs(nums[last_index]);

            if (first_index == last_index)
            {
                result[index_result] = std::pow(nums[first_index], 2);
                break;
            }
            else if (last_abs > first_abs)
            {
                result[index_result] = std::pow(nums[last_index], 2);
                --index_result;
                --last_index;
            }
            else if (first_abs > last_abs)
            {
                result[index_result] = std::pow(nums[first_index], 2);
                --index_result;
                ++first_index;
            }
            else if (first_abs == last_abs)
            {
                result[index_result] = std::pow(nums[last_index], 2);
                --index_result;
                result[index_result] = std::pow(nums[first_index], 2);
                --index_result;
                --last_index;
                ++first_index;
            }
        }

        return result;
    }
};
