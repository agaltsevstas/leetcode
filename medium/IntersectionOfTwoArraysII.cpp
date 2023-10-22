class Solution
{
public:
    // Time: O(n + m)
    // Memory: O(n + m)
    /*
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::unordered_map<int, int> nums_set;
        for (int i = 0, I = nums1.size(); i < I; ++i)
            nums_set[nums1[i]] += 1;

        std::vector<int> result;
        for (int i = 0, I = (int)nums2.size(); i < I; ++i)
        {
            nums_set[nums2[i]] -= 1;
            if (nums_set[nums2[i]] >= 0)
                result.push_back(nums2[i]);
        }

        return result;
    }
    */

    // Time: O(n + m)
    // Memory: O(n)
    /*
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::array<int, 1001> nums_array {};
        for (int i = 0, I = nums1.size(); i < I; ++i)
            nums_array[nums1[i]] += 1;

        std::vector<int> result;
        for (int i = 0, I = (int)nums2.size(); i < I; ++i)
        {
            nums_array[nums2[i]] -= 1;
            if (nums_array[nums2[i]] >= 0)
                result.push_back(nums2[i]);
        }

        return result;
    }
    */

    // Time: O(nlogn + mlogm)
    // Memory: O(min(n, m))
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        const int nums1_size = nums1.size();
        const int nums2_size = nums2.size();
        int nums1_pointer = 0, nums2_pointer = 0;

        std::vector<int> result;
        while (nums1_pointer < nums1_size && nums2_pointer < nums2_size)
        {
            if (nums1[nums1_pointer] == nums2[nums2_pointer])
            {
                result.emplace_back(nums1[nums1_pointer]);
                ++nums1_pointer;
                ++nums2_pointer;
            }
            else if (nums1[nums1_pointer] > nums2[nums2_pointer])
            {
                ++nums2_pointer;
            }
            else if (nums1[nums1_pointer] < nums2[nums2_pointer])
            {
                ++nums1_pointer;
            }
        }

        return result;
    }
};
