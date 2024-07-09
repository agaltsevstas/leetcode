// Time: O(logn)
// Time: O(k), где k - длина окна

class Solution {
public:
    std::vector<int> findClosestElements(vector<int>& arr, int k, int x) // [1,1,1,10,10,10], k = 1, x = 9
    {
        int left = 0;
        int right = arr.size() - k; // Последние k символы нет смысла просматривать

        while (left < right) // 0 < 5, 3 < 5, 3 < 3
        {
            int middle = (left + right) / 2; // 2, 4
            if (x - arr[middle] > arr[middle + k] - x) // 9 - 1 > 10 - 1,  9 - 10 > 10 - 9
            {
                left = middle + 1; // 3
            }
            else
            {
                right = middle; // 3
            }
        }

        return std::vector<int>(arr.begin() + right, arr.begin() + right + k);
    }
};
