// Time: O(n)
// Memory: O(n)

class Solution {
public:
    int compress(std::vector<char>& chars) // ["a","a","b","b","c","c","c"]
    {
        if (chars.size() == 1)
            return 1;

        std::string str;
        int count = 1;
        for (int i = 1, I = (int)chars.size(); i < I; ++i)
        {
            if (chars[i - 1] != chars[i]) // a == a, a != b, b == b, b != c, c == c, c == c
            {
                str += chars[i - 1];
                if (count > 1)
                {
                    str += std::to_string(count); // a2, a2b2
                    count = 1;
                }
            }
            else
            {
                ++count; // a = 2, b = 2, c = 2, c = 3
            }

            if (i == I - 1)
            {
                str += chars[i];
                if (count > 1)
                    str += std::to_string(count); // a2b2c3
            }
        }

        chars = std::vector<char>(str.begin(), str.end());
        return chars.size();
    }
};
