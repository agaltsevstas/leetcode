// Time: O(n/2)
// Memory: O(1)

class Solution {
public:
    bool isPalindrom(string s, int first_index, int last_index)
    {
        while (first_index <= last_index)
        {
            if (s[first_index] != s[last_index])
            {
                return false;
            }

            ++first_index;
            --last_index;
        }

        return true;
    }

    bool validPalindrome(string s) {
        auto length = s.length();
        int first_index = 0;
        int last_index = length - 1;

        while (first_index <= last_index)
        {
            if (s[first_index] != s[last_index])
            {
                return isPalindrom(s, first_index + 1, last_index) || isPalindrom(s, first_index, last_index - 1);
            }

            ++first_index;
            --last_index;
        }

        return true;
    }
};
