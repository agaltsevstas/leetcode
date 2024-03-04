// Time: O(n)
// Memory: O(1)

class Solution 
{
public:
    int scoreOfParentheses(string str)
    {
        int count = 0;
        int result = 0;
        char prev;
        for (const auto& s : str)
        {
            if (s == '(')
                ++count;
            else if (s == ')')
            {
                --count;
                if (prev == '(')
                    result += std::pow(2, count);
            }

            prev = s;
        }

        return result;
    }
};
