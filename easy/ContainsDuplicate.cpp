// 1 Способ: сортировка
// Time: O(nlogn + n) -> O(nlogn)
// Memory: O(1)

// 2 Способ: unordered_set
// Time: O(n)
// Memory: O(n)

class Solution {
public:
#if 1
    bool containsDuplicate(vector<int>& nums)
    {
        std::ranges::sort(nums);
        for (int i = 1, I = (int)nums.size(); i < I; ++i)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }

        return false;
    }
#endif

#if 0
    bool containsDuplicate(vector<int>& nums)
    {
        std::unordered_set<int> nums_set;
        for (const auto& num: nums)
        {
            if (nums_set.contains(num))
                return true;

            nums_set.insert(num);
        }

        return false;
    }
#endif
};
