// Time: O(n)
// Time: O(1)

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        auto size = nums.size();
        if (size <= 1)
            return true;

        std::optional<bool> isGreater;
        for (decltype(size) i = 0; i < size - 1; ++i)
        {
            auto difference = nums[i + 1] - nums[i];
            if (difference == 0)
                continue;

            if (isGreater.has_value())
            {
                if ((isGreater.value() == true) ^ (difference > 0))
                {
                    return false;
                }
            }
            else
            {
                isGreater = difference > 0;
            }
        }

        return true;
    }
};
