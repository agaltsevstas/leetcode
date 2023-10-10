// Time: O(logn)
// Memory: O(1)

class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 1)
            return x;

        int left = 0;
        int right = x;

        while (left < right - 1)
        {
            int64_t mid = (left + right) / 2;
            int64_t midSquare = mid * mid;
            if (midSquare < x)
            {
                left = mid;
            }
            else if (midSquare > x)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }

        return left;
    }
};
