// Time: O(max(n,m))
// Memory: O(1)

class Solution {
public:
    string addStrings(string nums1, string nums2)
    {
        const int nums1_size = nums1.size();
        const int nums2_size = nums2.size();
        const int min_size = std::min(nums1_size, nums2_size);
        const int max_size = std::max(nums1_size, nums2_size);
        std::string& result = nums1_size > nums2_size ? nums1 : nums2;

        int carry = 0;
        int i = 1;
        for (; i <= min_size; ++i)
        {
            int sum = (nums1[nums1_size - i] - '0') + (nums2[nums2_size - i] - '0') + carry;
            result[max_size - i] = sum % 10 + '0';
            carry = sum / 10;
        }

        while (i <= max_size)
        {
            int sum = (result[max_size - i] - '0') + carry;
            result[max_size - i] = sum % 10 + '0';
            carry = sum / 10;
            ++i;
        }

        if (carry != 0)
        {
            result.insert(result.begin(), carry + '0');
        }

        return result;
    }
};
