// Time: O(logn)
// Memory: O(1)

class Solution {
public:
    int findMin(vector<int>& nums)
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

        return nums[right];
    }
};
