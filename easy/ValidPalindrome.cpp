// Time: O(n/2)
// Memory: O(1)

class Solution {
public:
    bool isLetter(char x)
    {
        return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
    }

    bool isAlpha(char c)
    {
        return std::isalpha(c) || std::isdigit(c);
    }

    bool isPalindrome(string s) {
        auto length = s.length();
        int first_index = 0;
        int last_index = length - 1;

        while (first_index <= last_index)
        {
            if (!isAlpha(s[first_index]))
            {
                ++first_index;
                continue;
            }

            if (!isAlpha(s[last_index]))
            {
                --last_index;
                continue;
            }

            if (std::tolower(s[first_index]) != std::tolower(s[last_index]))
                return false;

            ++first_index;
            --last_index;
        }

        return true;
    }
};
