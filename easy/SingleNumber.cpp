// Time: O(n)
// Memory: O(1)

// arr = [7, 5, 7]
// 7 -> 111
// 5 -> 101
// 7^5= 010 -> 2
// 2^7= 101 -> 5

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for (const auto& num : nums)
            result ^= num;

        return result;
    }
};
