// Time: O(logn)
// Memory: O(1)

// nums[1, 2, 3, 4, 5] target = 4
//      0  1  2  3  4 left = 0, right = 5
// nums[(0 + 5) / 2] = nums[2] < 4, left = 2
// nums[(2 + 5) / 2] = nums[3] == 4, left = 3

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        auto size = nums.size();
        if (size < 0)
            return -1;

        int left = 0;
        int right = size; // Важный момент! Не size - 1!
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid;
            }
            else
            {
                return mid;
            }
        }

        return nums[left] == target ? 0 : -1;
    }
};
