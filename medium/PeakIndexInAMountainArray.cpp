// Time: O(logn)
// Memory: O(1)

class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        auto size = arr.size();
        if (size < 3)
            return -1;

        int left = 0;
        int right = size - 1; // Важный момент! Последний элемент не может быть ответом

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                left = mid;
            }
        }

        return right;
    }
};
