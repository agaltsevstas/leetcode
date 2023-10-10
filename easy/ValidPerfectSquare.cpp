// Time: O(logn)
// Memory: O(1)

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return num;
            
        int left = 0;
        int right = num;

        while (left < right - 1)
        {
            int64_t mid = (left + right) / 2;
            int64_t midSqrt = mid * mid;
            
            if (midSqrt < num)
            {
                left = mid;
            }
            else if (midSqrt > num)
            {
                right = mid;
            }
            else
            {
                return true;
            }
        }

        return left * left == num;
    }
};
