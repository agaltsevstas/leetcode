// Time: O(logn)
// Memory: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> nums_map;
        for (const auto& num: nums)
        {
            nums_map[num] += 1;
        }

        auto compare = [](const pair<int, int>& lhs, const pair<int, int>& rhs)
        {
            return lhs.second < rhs.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> heap;
        for (const auto& [num, count] : nums_map)
        {
            heap.push(std::make_pair(num, count));
        }

        std::vector<int> result(k);
        for (int i = 0; i < k; ++i)
        {
            result[i] = heap.top().first;
            heap.pop();
        }

        return result;
    }
};
