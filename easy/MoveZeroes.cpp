// Time: O(n)
// Memory: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto size = nums.size();
        if (size <= 1)
            return;

        int is_no_zero = 0;
        int is_zero = -1;

        while (is_no_zero < size)
        {
            if (nums[is_no_zero] == 0 && is_zero < 0)
            {
                is_zero = is_no_zero;
            }
            else if (nums[is_no_zero] != 0 && is_zero >= 0)
            {
                std::swap(nums[is_no_zero], nums[is_zero]);
                ++is_zero;
            }

            ++is_no_zero;
        }
    }
};
