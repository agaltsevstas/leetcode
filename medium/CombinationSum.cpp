// Time: O(n!)
// Memory: ?

class Solution
{
public:

    void backTracking(const int iTarget, int iSum, const std::vector<int>& iNumbers, const size_t iIndex, std::vector<int>& iCurTarget, std::vector<std::vector<int>>& oResult)
    {
        if (iSum > iTarget)
        {
            return;
        }
        else if (iSum == iTarget)
        {
            oResult.emplace_back(iCurTarget);
            return;
        }

        for (size_t i = iIndex, I = iNumbers.size(); i < I; ++i)
        {
            backTracking(iTarget, iSum + iCurTarget.emplace_back(iNumbers[i]), iNumbers, i, iCurTarget, oResult);
            iCurTarget.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& numbers, int target)
    {
        std::vector<int> iCurTarget;
        std::vector<std::vector<int>> result;
        std::sort(numbers.begin(), numbers.end());
        backTracking(target, 0, numbers, 0, iCurTarget, result);

        return result;
    }
};
