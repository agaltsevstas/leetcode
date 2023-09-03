// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto size = nums.size();
        decltype(size) arith_progress_sum = 0;
        for (decltype(size) i = 1; i <= size; ++i)
            arith_progress_sum += i;

        auto result_sum = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());
        return arith_progress_sum - result_sum;
    }
};
