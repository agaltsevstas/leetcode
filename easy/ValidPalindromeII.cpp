// Time: O(n/2)
// Memory: O(1)

class Solution {
public:
    bool isPalindrom(int left, int right, const std::string& s)
    {
        while (left <= right)
        {
            if (s[left] != s[right])
                return false;

            ++left;
            --right;
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int left = 0;
        int right = (int)s.size() - 1;
        while (left <= right)
        {
            if (s[left] != s[right])
                return isPalindrom(left + 1, right, s) || isPalindrom(left, right - 1, s);

            ++left;
            --right;
        }

        return true;
    }
};
