// Time: O(n)
// Memory: O(k), k - число уникальных символов в строке

class Solution {
public:
#if 1
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_set<char> letter_map;
        size_t max = 0;
        for (size_t i = 0, j = 0; i < s.size(); ++i)
        {
            if (letter_map.contains(s[i]))
            {
                while (letter_map.contains(s[i])) // baca: "ba" - часть нужно занулить, т.к идем до 'a'
                {
                    letter_map.erase(s[j]);
                    ++j;
                }

                letter_map.insert(s[i]);
            }
            else
            {
                letter_map.insert(s[i]);
                max = std::max(max, i - j + 1); // потому что j начинается с 0
            }
        }

        return max;
    }
#endif
#if 0
    int lengthOfLongestSubstring(string s)
    {
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
#endif
};
