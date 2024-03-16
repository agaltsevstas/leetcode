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
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) // Средний элемент тоже нужно пройти
        {
            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
        }

        return -1;
    }
};
