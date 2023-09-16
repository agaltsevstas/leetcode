// Time: O(n)
// Memory: O(k), k - число уникальных символов в строке

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        auto size = s.size();
        if (size <= 1)
            return -1;

        int max = -1;
        std::vector<int> letter_map(123, 0); // a-z - 97-122 в ASCII
        for (int i = 0; i < size; ++i)
        {
            if (letter_map[(int)s[i]] > 0)
            {
                max = std::max(max, i - (letter_map[(int)s[i]]));
            }
            else
            {
                letter_map[(int)s[i]] = i + 1; // сохраняем индекс, +1 потому что может быть первый 0 индекс
            }
        }

        return max;
    }
};
