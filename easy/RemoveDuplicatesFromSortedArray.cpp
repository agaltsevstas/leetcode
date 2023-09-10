// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto size = nums.size();
        if (size <= 1)
            return size;

        int count = 1;
        int count_dublicate = 0;
        int first_index = 1;
        int last_index = size - 1;

        while (first_index <= last_index)
        {
            if (nums[first_index] == nums[first_index - 1])
            {
                ++count_dublicate;
            }
            else
            {
                if (count_dublicate > 0)
                {
                    for (size_t i = first_index; i <= last_index; ++i)
                    {
                        nums[i - count_dublicate] = nums[i];
                    }

                    last_index -= count_dublicate;
                    first_index -= count_dublicate;
                    count_dublicate = 0;
                    continue;
                }

                ++count;
            }
            
            ++first_index;
        }

        nums.resize(count);
        return count;
    }
};
