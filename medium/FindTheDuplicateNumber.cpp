// Time: O(n)
// Memory: O(1)

class Solution {
public:
#if 1
    // Сделать из массива список и найти в нем цикл
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums.front();
        int fast = nums.front();

        // [1,3,4,2,2]
        while (true)
        {
            slow = nums[slow];       // 3, 2
            fast = nums[nums[fast]]; // 2, 2
            if (slow == fast)
                break;
        }

        slow = nums.front(); // Сбрасываем в самое начало
        while (slow != fast) // по 1 шагу оба указателя
        {
            slow = nums[slow]; // 3, 2
            fast = nums[fast]; // 4, 2
        }

        return slow;
    }
#endif
#if 0
    int findDuplicate(vector<int>& nums)
    {
        // [1,3,4,2,2]
        for (int i = 0, I = (int)nums.size(); i < I;)
        {
            int num = nums[i]; // 1, 3, 4, 2, 4, 2
            if (i == num - 1) // 0 == 1 - 1, 1 != 3 - 1, 1 != 4 - 1, 1 == 2 - 1, 2 == 3 - 1, 3 == 4 - 1, 4 != 2 - 1
                ++i; // 1, 2, 3, 4
            else if (num == nums[num - 1]) 3 != 4, 4 != 2, 2 == 2
                return num; // 2
            else
            {
                nums[i] = nums[num - 1]; // 3 = 4, 4 = 2
                nums[num - 1] = num;  // 4 = 3, 2 = 4
                // [1,4,3,2,2], // [1,2,3,4,2]
            }
        }

        return -1;
    }
#endif
};
