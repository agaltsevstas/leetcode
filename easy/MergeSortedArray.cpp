// Time: O(m + n)
// Memory: O(m + n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int first = 0;
        int second = 0;

        std::vector<int> result;
        result.reserve(m + n);
        while (first < m && second < n)
        {
            if (nums1[first] <= nums2[second])
                result.emplace_back(nums1[first++]);
            else
                result.emplace_back(nums2[second++]);
        }

        while (first < m)
            result.emplace_back(nums1[first++]);

        while (second < n)
            result.emplace_back(nums2[second++]);

        nums1 = result;
    }
};
