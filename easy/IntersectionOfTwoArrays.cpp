// Time: O(n), потому что nums1.length == nums2.length
// Memory: O(2n) -> O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        vector<int> nums1_map(1001, 0);
        for (auto& num1 : nums1)
        {
            nums1_map[num1] = 1;
        }

        vector<int> result;
        for (auto& num2 : nums2)
        {
            if (nums1_map[num2] == 1)
            {
                result.emplace_back(num2);
                nums1_map[num2] = 0;
            }
        }

        return result;
    }
};
