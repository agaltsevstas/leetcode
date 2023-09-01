// Time: O(n)
// Memory: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        auto size = nums.size();
        if (size == 0)
            return -1;

        decltype(size) count = 0, cur_sum = 0;
        std::map<decltype(size), decltype(size)> px;
        px[0] = 1;
        for (decltype(size) i = 0; i < size; ++i)
        {
            cur_sum += nums[i];
            auto difference = cur_sum - k;
            if (auto it = px.find(difference); it != px.end())
                count += px[difference];

            if (auto it = px.find(cur_sum); it == px.end())
                px[cur_sum] == 0;
            px[cur_sum] += 1;
        }

        return count;
    }
};
