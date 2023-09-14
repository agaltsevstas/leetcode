// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int size = s.size();
        if (size <= 1)
            return size;

        std::vector<int> letter_map(255); // a-z - 97-122 в ASCII
        int max = 0;
        for (int i = 0, j = 0; i < size; ++i)
        {
            if (letter_map[(int)s[i]] == 0)
            {
                letter_map[(int)s[i]] = 1;
                max = std::max(max, i - j + 1);
            }
            else
            {
                while (letter_map[(int)s[i]] == 1) // baca: "ba" - часть нужно занулить, т.к идем до 'a'
                {
                    letter_map[(int)s[j]] = 0;
                    ++j;
                }

                letter_map[(int)s[i]] = 1;
            }
        }

        return max;
    }
};
