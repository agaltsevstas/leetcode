// Time: O(n)
// Memory: O(1)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto size = nums.size();
        if (size == 1)
            return nums[0];

        double sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }

        double result = sum / k;
        if (k == size)
            return result;

        for (decltype(size) i = k; i < size; ++i)
        {
            sum += (nums[i] - nums[i - k]);
            result = std::max(result, sum / k);
        }

        return result;
    }
};
