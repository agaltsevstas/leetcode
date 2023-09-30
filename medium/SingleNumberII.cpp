// Time: O(n)
// Memory: O(1)

// arr = [7, 7, 7, 1]
// 7 -> 111 = [1,1,1]
// 7 -> 111 = [2,2,2]
// 7 -> 111 = [3,3,3]
// 1 -> 001 = [4,3,3]

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        constexpr int size = 32;
        std::array<int, size> bits;
        bits.fill(0);
        for (int64_t num : nums)
        {
            int i = 0;
            num += std::numeric_limits<int>::max();
            while (num != 0)
            {
                bits[i] += num % 2;
                bits[i] %= 3;
                num /= 2;
                ++i;
            }
        }

        int64_t result = 0;
        for (int i = 0; i < size; ++i)
        {
            result += bits[i] * std::pow(2, i);
        }

        return result - std::numeric_limits<int>::max();
    }
};
