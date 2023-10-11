// Time: O(logn)
// Memory: O(1)

int searchFirst(vector<int>& nums, int target)
{
    int left = -1;
    int right = (int)nums.size() - 1;

    while (left < right - 1)
    {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid;
        }
        else if (nums[mid] >= target)
        {
            right = mid;
        }
    }

    return nums[right] == target ? right : -1;
}

int searchLast(vector<int>& nums, int target)
{
    int left = 0;
    int right = (int)nums.size();

    while (left < right - 1)
    {
        int mid = (left + right) / 2;
        if (nums[mid] <= target)
        {
            left = mid;
        }
        else if (nums[mid] > target)
        {
            right = mid;
        }
    }

    return nums[left] == target ? left : -1;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
            
        return {searchFirst(nums, target), searchLast(nums, target)};
    }
};
