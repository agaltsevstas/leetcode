class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        auto size = nums.size();
        for (decltype(size) i = 0; i < size;)
        {
            int n = nums[i];
            if (i == n - 1)
                i++;
            else if (n == nums[n - 1])
                return n;
            else if (i != n - 1)
            {
                nums[i] = nums[n - 1];
                nums[n - 1] = n;
            }
        }

        return -1;
    }
};
