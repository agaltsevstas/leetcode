// n - число символов строки, k - число уникальных символов
// Time: O(n * k)
// Memory: O(k)

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        const int p_size = (int)p.size();
        const int s_size = (int)s.size();
        if (p_size > s_size)
            return {};

        constexpr int map_size = 26; // a-z - 97-122 в ASCII
        vector<int> s_map(map_size, 0), p_map(map_size, 0);
        
        for (int i = 0; i < p_size; ++i)
        {
            ++s_map[(int)s[i] - 'a'];
            ++p_map[(int)p[i] - 'a'];
        }

        std::vector<int> indicies;
        if (p_map == s_map)
                indicies.emplace_back(0);

        for (int i = p_size; i < s_size; ++i)
        {
            ++s_map[(int)s[i] - 'a'];
            --s_map[(int)s[i - p_size] - 'a'];

            if (p_map == s_map)
                indicies.emplace_back(i - p_size + 1);
        }

        return indicies;
    }
};
