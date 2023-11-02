// Time: O( size(abc)^n )
// Memory: O( size(abc)^n )

class Solution
{
    std::unordered_map<char, std::string> numbers =
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void backTracking(const std::string& iDigits, int iIndex, std::string& iCurResult, std::vector<std::string>& oResult)
    {
        if (iDigits.size() == iCurResult.size())
        {
            oResult.emplace_back(iCurResult);
            return;
        }

        for (const auto& digit : numbers[iDigits[iIndex]])
        {
            iCurResult += digit;
            backTracking(iDigits, iIndex + 1, iCurResult, oResult);
            iCurResult.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.empty())
            return {};

        std::vector<std::string> result;
        std::string curResult;
        backTracking(digits, 0, curResult, result);

        return result;
    }
};
