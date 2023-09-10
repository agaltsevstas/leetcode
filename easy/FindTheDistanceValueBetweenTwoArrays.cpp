// Time: O((n + m) * log(n))
// Memory: O(1)

class Solution
{
    int binarySearch(vector<int>& nums, int number, int d)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < number - d)
            {
                left = mid + 1;
            }
            else if (nums[mid] > number + d)
            {
                right = mid - 1;
            }
            else
            {
                return 0;
            }
        }

        return 1;
    }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());

        int count = 0;
        for (int i = 0, I = arr1.size(); i < I; ++i)
            count += binarySearch(arr2, arr1[i], d);

        return count;
    }
};
