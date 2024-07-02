// Time: O(n)
// Memory: O(1)

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums)  // [4,3,2,7,8,2,3,1]
    {
        std::vector<int> duplicates;
        for (int i = 0, I = (int)nums.size(); i < I; ++i) // 0, 1, 2, 3, 4, 5, 6, 7
        {
            auto& node = nums[abs(nums[i]) - 1]; // 7, 2, 3, 3, 1, -3, -2, 4

            if (node < 0) // 7 < 0, 2 < 0, 3 < 0, 3 < 0, 1 < 0
            {
                duplicates.push_back(abs(nums[i])); // -3, -2
                continue;
            }

            node *= -1; // [4,3,2,-7,8,2,3,1], [4,3,-2,-7,8,2,3,1], [4,-3,-2,-7,8,2,3,1], [4,-3,-2,-7,8,2,-3,1], [4,-3,-2,-7,8,2,-3,-1], [-1,-3,-2,-7,8,2,-3,-1]
        }

        return duplicates;
    }
};
