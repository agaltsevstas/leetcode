// Time: O(n)
// Memory: O(n)

class Solution {
public:
    std::vector<int> sortedSquares(vector<int>& nums)
    {
        const int size = (int)nums.size();
        int first = 0;
        int last = size - 1;
        int cur = last;
        
        std::vector<int> result(size);
        while (first <= last)
        {
            if (std::abs(nums[first]) <= std::abs(nums[last]))
            {
                result[cur--] = std::pow(nums[last--], 2);
            }
            else
            {
                result[cur--] = std::pow(nums[first++], 2);
            }
        }

        return result;
    }
};
