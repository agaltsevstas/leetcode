// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        auto size = s.size();
        if (size <= 1)
            return size;

        std::vector<int> letter_map(91, 0); // A-Z - 65-90 в ASCII
        int maxCount = 0;
        int maxLength = 0;
        for (int i = 0, j = 0; i < size; ++i)
        {
            letter_map[s[i]] += 1;
            maxCount = max(maxCount, letter_map[s[i]]);
            while ((i - j + 1) - maxCount > k)
            {
                letter_map[s[j]] -= 1;
                ++j;
            }

            maxLength = std::max(maxLength, i - j + 1);
        }

        return maxLength;
        }
}; 
