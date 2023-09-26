// Time: O(1)
// Memory: O(1)

class Solution {
public:
    int reverse(int x)
    {
        int coef = 1;
        int64_t result = 0;
        while (x != 0)
        {
            result *= coef;
            result += x % 10;

            if (result > std::numeric_limits<int>::max() ||
                result < std::numeric_limits<int>::min())
                {
                    return 0;
                }

            x /= 10;
            coef = 10;
        }

        return (int)result;
    }
};
