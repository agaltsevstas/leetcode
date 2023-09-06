// Time: O(n)
// Memory: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int offset = 5 * std::pow(10, 4);
        auto size = offset * 2 + 1;
        std::vector<int> nums_map(offset * 2 + 1, 0);
        for (const auto& num: nums)
        {
            nums_map[num + offset] += 1;
        }

        std::vector<std::vector<int>> nums_reverse_map(size);
        for (size_t i = 0, I = nums_map.size(); i < I; ++i)
        {
            if (nums_map[i] >= 1)
            {
                auto num_map = nums_reverse_map[nums_map[i]];
                num_map.emplace_back(i - offset);
                nums_reverse_map[nums_map[i]] = num_map;
            }
        }


        int i = 0;
        std::vector<int> result;
        while (k > 0)
        {
            auto last_index = size - i - 1;
            if (!nums_reverse_map[last_index].empty())
            {
                auto min = std::min(k, (int)nums_reverse_map[last_index].size());
                for (int j = 0; j < min; j++)
                {
                    result.emplace_back(nums_reverse_map[last_index][j]);
                    --k;
                }
            }
            ++i;
        }

        return result;
    }
};
