// Time: O(n!)
// Memory: O(n!)

class Solution
{
public:
    void backTraking(const std::vector<int>& iNums, std::vector<int>& iCurNums, std::unordered_set<int>& iUsed, std::vector<std::vector<int>>& oResult)
    {
        if (iCurNums.size() == iNums.size())
        {
            oResult.emplace_back(iCurNums);
            return;
        }

        for (const auto& num: iNums)
        {
            if (iUsed.contains(num))
                continue;

            iCurNums.emplace_back(num);
            iUsed.insert(num);

            backTraking(iNums, iCurNums, iUsed, oResult);
            iCurNums.pop_back();
            iUsed.extract(num);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        std::unordered_set<int> used;
        std::vector<int> curNums;
        
        backTraking(nums, curNums, used, result);
        
        return result;
    }
};
