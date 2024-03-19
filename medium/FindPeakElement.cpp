// Time: O(log n)
// Memory: O(1)

/*
1,2,1,3,5,6,4   left = 0, right = 6, mid = 3
0,1,2,3,4,5,6   left = 4, right = 6, mid = 5
*/

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) // при right == 1 пропускаем, поэтому строгое решение
        {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid; // !!!
        }

        return left;
    }
};
