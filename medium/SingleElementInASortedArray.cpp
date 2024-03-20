// Time: O(logn)
// Memory: O(1)

/*
Важно: можно обратить внимание: первое вхождение числа - четные индекс, второе вхождение числа - нечетный индекс!
1,1,2,2,3,3,4,8,8 left = 0, right = 8, mid = 4
0,1,2,3,4,5,6,7,8 left = 6, right = 8, mid = 6
                  left = 6, right = 6

3,3,7,7,10,11,11 left = 0, right = 6, mid = 3
0,1,2,3,4, 5, 6  left = 4, right = 6, mid = 5
                 left = 4, right = 4
*/

class Solution
{
public:
#if 1
    int singleNonDuplicate(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) // конкретный элемент искать не нужно, поэтому строгое меньше
        {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) // делаем всегда четный индекс, иначе уменьшаем, чтобы потом прыгнуть сразу на 2 индекса
                --mid;
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                    left = mid + 2;
                else
                    right = mid;
            }
        }

        return nums[right];
    }
#endif
#if 0
    int singleNonDuplicate(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) // конкретный элемент искать не нужно, поэтому строгое меньше
        {
            int mid = (left + right) / 2;
            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                    left = mid + 2;
                else
                    right = mid;
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return nums[right];
    }
#endif
};
