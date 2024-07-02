// Time: O(1)
// Memory: O(1)

class Solution {
public:
    int reverse(int x)
    {
        int64_t result = 0;
        while (abs(x) != 0)                  // 123, 12, 1
        {
            int division = x % 10;           // 3, 2, 1
            x /= 10;                         // 12, 1, 0
            result = 10 * result + division; // 3, 32, 321

            if (result > std::numeric_limits<int>::max() ||
                result < std::numeric_limits<int>::min())
            {
                return 0;
            }
        }

        return (int)result;
    }
};
