// Time: O(n)
// Memory: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int count = 0;
        int cur_sum = 0;
        std::map<int, int> sum_map = {{0, 1}};
        for (const auto& num : nums)
        {
            cur_sum += num;
            auto difference = cur_sum - k;

            if (sum_map.contains(difference))
                count += sum_map[difference];

            sum_map[cur_sum] = 1;
        }

        return count;
    }
};
