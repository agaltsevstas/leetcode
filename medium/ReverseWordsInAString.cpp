// Time: O(n^2)
// Memory: O(n)

class Solution {
public:
    string reverseWords(string s)
    {
        const int s_size = (int)s.size();
        std::string result;
        bool isSpace = false;
        for (int i = 0, j = 0; i < s_size; ++i)
        {
            if (s[i] == ' ')
            {
                if (isSpace)
                {
                    auto result_size = result.size();
                    result.resize(result.size() + i + 1);
                    for (int z = j; z <= i; ++z)
                    {
                        result[result_size + z - 1] = s[z];
                    }

                    isSpace = false;
                }
            }
            else
            {
                if (!isSpace)
                {
                    isSpace = true;
                    j = i;
                }
            }
        }

        return result;
    }
};
