// Time: O(log(m+n)), где m - длина 1 массива, n - длина 2 массива
// Memory: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() > nums2.size())
        std::swap(nums1, nums2);
  
        int left = 0;
        int right = (int)nums1.size();
        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();
        
        /*
        1,2,3,6 left = 0, right = 2, mid1 = 1, mid2 = 2, left1 = 4, right1 = 5, left2 = 2, right2 = 3; 4 < 3 && 5 > 2
        4,5     left = 0, right = 0, mid1 = 0, mid2 = 3, left1 = min, right1 = 4, left2 = 3, right2 = 6; min < 6 && 4 > 3

        */
        while (true)
        {
            int mid1 = (left + right) / 2;
            int mid2 = (size1 + size2 + 1) / 2 - mid1;
            
            int left1 = mid1 == 0 ? std::numeric_limits<int>::min() : nums1[mid1 - 1]; // max
            int right1 = mid1 == size1 ? std::numeric_limits<int>::max() : nums1[mid1]; // min
            
            int left2 = mid2 == 0 ? std::numeric_limits<int>::min() : nums2[mid2 - 1]; // max
            int right2 = mid2 == size2 ? std::numeric_limits<int>::max() : nums2[mid2]; // min
            
            if (left1 <= right2 && right1 >= left2)
            {
                if ((size1 + size2) % 2 == 0)
                    return (double)(std::max(left1, left2) + std::min(right1, right2)) / 2;
                else
                    return std::max(left1, left2);
            }
            else if (left1 > right2)
            {
                right = mid1 - 1;
            }
            else
            {
                left = mid1 + 1;
            }
        }
        
        return left;
    }
};
