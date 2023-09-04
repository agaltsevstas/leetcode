// Time: O(n)
// Memory: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto size = numbers.size();
        int first_index = 0;
        int last_index = size - 1;

        vector<int> sum;
        while (first_index < last_index)
        {
            auto cur_sum = numbers[last_index] + numbers[first_index];
            if (cur_sum > target)
            {
                --last_index;
            }
            else if (cur_sum < target)
            {
                ++first_index;
            }
            else
            {
                sum = vector<int>{first_index + 1, last_index + 1};
                break;
            }

            
        }

        return sum;
    }
};
