// Time: O(m + n)
// Memory: O(m + n)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> result(m + n);
        int result_index = -1;
        int nums1_index = 0;
        int nums2_index = 0;
        
        while (nums1_index < m || nums2_index < n)
        {
            if (nums1_index == m)
            {
                for (; nums2_index < n; ++nums2_index)
                {
                    result[++result_index] = nums2[nums2_index];
                }

                break;
            }
            else if (nums2_index == n)
            {
                for (; nums1_index < m; ++nums1_index)
                {
                    result[++result_index] = nums1[nums1_index];
                }

                break;
            }
            else if (nums1[nums1_index] == nums2[nums2_index])
            {
                result[++result_index] = nums1[nums1_index];
                ++nums1_index;
                result[++result_index] = nums2[nums2_index];
                ++nums2_index;
            }
            else if (nums1[nums1_index] > nums2[nums2_index])
            {
                result[++result_index] = nums2[nums2_index];
                ++nums2_index;
            }
            else if (nums2[nums2_index] > nums1[nums1_index])
            {
                result[++result_index] = nums1[nums1_index];
                ++nums1_index;
            }
        }

        nums1 = result;
    }
};
