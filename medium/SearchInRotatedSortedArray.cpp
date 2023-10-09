// Time: O(logn)
// Memory: O(1)

class Solution {
public:
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
};
