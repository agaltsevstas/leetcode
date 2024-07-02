// Time: O(n)
// Memory: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) // nums = [2,7,11,15], target = 9
    {
        std::unordered_map<int, int> numbers;
        for (int i = 0, I = (int)nums.size(); i < I; ++i) // 0, 1
        {
            auto difference = target - nums[i]; // 7, 2
            if (auto it = numbers.find(difference); it != numbers.end())
                return {it->second, i};

            numbers.insert({nums[i], i}); // [7, 0]
        }
        return {};
    }
};
