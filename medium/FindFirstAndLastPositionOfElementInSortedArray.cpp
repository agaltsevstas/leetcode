// Time: O(logn)
// Memory: O(1)
// Может быть 88888888
/*
target == 8
loop 1, nums[mid] >= target:
5,7,7,8,8,10 left = 0, right = 5, mid = 2
0,1,2,3,4,5  left = 3, right = 5, mid = 5
begin = left = 3

loop 2, nums[mid] <= target:
5,7,7,8,8,10 left = 0, right = 5, mid = 2
0,1,2,3,4,5  left = 3, right = 5, mid = 4
             left = 5, right = 5, mid = 5
             left = 5, right = 4
end = right = 4

target == 6
loop 1, nums[mid] >= target:
5,7,7,8,8,10 left = 0, right = 5, mid = 2
0,1,2,3,4,5  left = 0, right = 1, mid = 1
             left = 1, right = 1, mid = 1,
             left = 1, right = 0
begin = left = 1

loop 2, nums[mid] <= target:
5,7,7,8,8,10 left = 0, right = 5, mid = 2
0,1,2,3,4,5  left = 0, right = 1, mid = 0
             left = 1, right = 1, mid = 1
             left = 1, right = 0
end = right = 0
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty())
            return {-1, -1};

        int left = 0;
        int right = nums.size() - 1;
        int begin = -1; // не делать -1, иначе не пройдет проверку в конце
        int end = -1; // не делать -1, иначе не пройдет проверку в конце

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        begin = left;

        left = 0;
        right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        end = right;

        if (begin > end)
            return {-1, -1};
        /*
        if (nums[begin] == target && nums[end] == target) // не делать так, индексы могут быть отрицательными
            return {begin, end};
        */
        return {begin, end};
    }
};
