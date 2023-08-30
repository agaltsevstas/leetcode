// Time: O(n)
// Time: O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            std::swap(nums[left], nums[right]);
            
            ++left;
            --right;
        }
        
        left = 0;
        right = k - 1;
        while (left <= right)
        {
            std::swap(nums[left], nums[right]);

            ++left;
            --right;
        }
        
        left = k;
        right = nums.size() - 1;
        while (left <= right)
        {
            std::swap(nums[left], nums[right]);
            
            ++left;
            --right;
        }
    }
};
