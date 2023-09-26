// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        int max1 = std::numeric_limits<int>::min();
        int max2 = std::numeric_limits<int>::min();
        int max3 = std::numeric_limits<int>::min();
        int min1 = std::numeric_limits<int>::max();
        int min2 = std::numeric_limits<int>::max();

        for (const auto& num : nums)
        {
            if (num > max3)
            {
                if (num > max2)
                {
                    if (num > max1)
                    {
                        max3 = max2;
                        max2 = max1;
                        max1 = num;
                    }
                    else
                    {
                        max3 = max2;
                        max2 = num;
                    }
                }
                else
                {
                    max3 = num;
                }
            }
            if (num < min2)
            {
                if (num < min1)
                {
                    min2 = min1;
                    min1 = num;
                }
                else
                {
                    min2 = num;
                }
            }
        }

        return std::max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
