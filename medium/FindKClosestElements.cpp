// Time: O(logn)
// Time: O(k), где k - длина окна

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        int left = -1;
        int right = (int)arr.size() - k;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + right, arr.begin() + (right + k));
    }
};
