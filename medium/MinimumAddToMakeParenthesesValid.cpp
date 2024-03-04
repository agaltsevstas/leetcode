// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int minAddToMakeValid(string str)
    {
        int count = 0;
        int result = 0;
        for (const auto& s : str)
        {
            if (s == '(')
                ++count;
            else if (s == ')')
            {
                if (count > 0)
                   --count;
                else
                    ++result;
            }
        }

        return result + count;
    }
};
