// Time: O(logn)
// Memory: O(1)


class Solution 
{
public:
#if 1
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid]) // Ищем перепад пика
            {
                if (nums[left] <= target && target < nums[mid]) // left может быть тем самым индексом, поэтому <=
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[right]) // right может быть тем самым индексом, поэтому <=
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
#endif
#if 0
int findOffset(vector<int>& nums)
    {
        int left = -1;
        int right = (int)nums.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums.back())
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        return right;
    }

    int search(vector<int>& nums, int target)
    {
        int size = (int)nums.size();
        int left = 0;
        int right = size;
        
        int offset = findOffset(nums);
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (nums[(mid + offset) % size] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        
        left = (left + offset) % size;
        return nums[left] == target ? left : -1;
    }
#endif
};
