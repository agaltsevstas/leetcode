// Числа Каталана
// 1, 1, 2, 5 (increase)
//*
// 5, 2, 1, 1 (reverse)
// ----------
// 5 + 2 + 2 + 5 = 14

// Time: O(n - индекс числа Каталана)
// Memory: O(2n * число Каталана)

class Solution
{
    void backTracking(const int count, int iBalance, std::string& iCurResult, std::vector<std::string>& oResult)
    {
        if (iBalance < 0 || iBalance > count - iCurResult.size())
            return;
        
        if (count == iCurResult.size())
        {
            oResult.emplace_back(iCurResult);
            return;
        }

        for (const auto& [brace, newBalance] : {std::pair('(', iBalance + 1), std::pair(')', iBalance - 1)})
        {
            iCurResult += brace;
            backTracking(count, newBalance, iCurResult, oResult);
            iCurResult.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int count)
    {
        int braces = 0;
        std::string curResult;
        std::vector<std::string> result;
        backTracking(count * 2, braces, curResult, result); // Увеличиваем в 2 раза, т.к. должна быть пара ()

        return result;
    }
};
