/*
 1 Способ: Алгоритм голосования Мура
 Time: O(n)
 Memory: O(1)
*/

/*
 2 Способ: std::sort
 Time: O(nlogn)
 Memory: O(1)
*/
/*
 3 Способ: std::map
 Time: O(n)
 Memory: O(n)
*/

class Solution {
public:

#if 1
    int majorityElement(vector<int>& nums)
    {
        int majority = 0;

        for (int count = 0; const auto& num : nums)
        {
            if (count == 0)
                majority = num;

            if (num == majority)
                ++count;
            else
                --count;
        }

        return majority;
    }
#endif

#if 0
    int majorityElement(vector<int>& nums)
    {
        std::ranges::sort(nums);
        return nums[nums.size() / 2];
    }
#endif

#if 0
    int majorityElement(vector<int>& nums)
    {
        std::map<int, int> nums_map;
        for (const auto& num : nums)
            nums_map[num] += 1;

        const int half = (int)nums.size() / 2;
        for (auto it = nums_map.rbegin(); it != nums_map.rend(); ++it)
        {
            if (it->second > half)
                return it->first;
        }

        return -1;
    }
#endif
};
