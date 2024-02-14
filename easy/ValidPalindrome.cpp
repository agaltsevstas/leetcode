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

    bool isPalindrome(string s)
    {
        int first = 0;
        int last = s.length() - 1;

        while (first < last) // средний символ необязательно смотреть
        {
            if (!isAlpha(s[first]))
            {
                ++first;
                continue;
            }

            if (!isAlpha(s[last]))
            {
                --last;
                continue;
            }

            if (std::tolower(s[first]) != std::tolower(s[last]))
                return false;

            ++first;
            --last;
        }

        return true;
    }
};
