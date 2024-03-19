// Time: O(logn)
// Memory: O(1)

class Solution {
public:
    int mySqrt(int x)
    {
        int left = 0;
        int right = x; // нельзя делить на 2 для x == 1

        while (left <= right)
        {
            uint64_t mid = (left + right) / 2; // Обязательно переводим в uint64_t, иначе при int*int == int
            uint64_t sqrt = mid * mid;
            if (sqrt == x)
                return mid;
            else if (sqrt < x)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right;
    }
};
