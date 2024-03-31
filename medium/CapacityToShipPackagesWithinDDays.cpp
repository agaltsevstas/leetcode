// Time: O(nlog(m))), где m - сумма всех элементов массива
// Memory: O(1)


class Solution
{
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int min = 0;
        int max = 0;
        for (const auto& weight : weights)
        {
            if (weight > min)
                min = weight;
            max += weight;
        }

        // 3,2,2,4,1,4
        while (min < max) // min = 4, max = 16; min = 4, max = 10; min = 4, max = 7; min = 6, max = 7
        {
            int pieces = 1, sum = 0;
            int mid = (min + max) / 2; // mid = 8; mid = 7; mid = 5; mid = 6
            for (const auto& elem : weights)
            {
                sum += elem; // sum = 3, sum = 5, sum = 7, sum = 11, sum = 5, sum = 9; sum = 3, sum = 5, sum = 7, sum = 11, sum = 5, sum = 9; sum = 3, sum = 5, sum = 7, sum = 6, sum = 4, sum = 5, sum = 9; sum = 3, sum = 5, sum = 7, sum = 6, sum = 7, sum = 5
                if (sum > mid)
                {
                    ++pieces; // pieces = 2; pieces = 2; pieces = 2, pieces = 3, pieces = 4, pieces = 2, pieces = 3
                    sum = elem; // sum = 4; sum = 4, sum = 4; sum = 2, sum = 4, sum = 4; sum = 2, sum = 1
                }
            }
            if (pieces > days)
                min = mid + 1; // min = 6
            else
                max = mid; // max = 10; max = 7; max = 6
        }

        return min;
    }
};
