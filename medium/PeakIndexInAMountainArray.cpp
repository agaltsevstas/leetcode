// Time: O(logn)
// Memory: O(1)

/*
0,10,5,2   left = 0, right = 3, mid = 1
0, 1,2,3   left = 0, right = 1, mid = 0
           left = 1, right = 1
*/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int left = 0;
        int right = arr.size() - 1; // Важный момент! Последний элемент не может быть ответом

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }

        return right;
    }
};
