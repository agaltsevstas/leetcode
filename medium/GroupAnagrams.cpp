// n - кол-во слов, m - макс кол-во букв, k - кол-во уникальных символов
// Time: O(n * m + k)
// Memory: O(n * m + k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        constexpr int key_size = 26; // a-z - 97-122 в ASCII
        std::map<std::array<int, key_size>, std::vector<std::string>> strs_map;

        for (int i = 0, I = (int)strs.size(); i < I; ++i)
        {
            std::array<int, key_size> key {};
            for (int j = 0, J = strs[i].size(); j < J; ++j)
            {
                key[(int)strs[i][j] - 97] += 1;
            }

            strs_map[key].emplace_back(strs[i]);
        }

        const auto strs_map_size = strs_map.size();
        std::vector<std::vector<string>> new_strs(strs_map_size);
        int i = 0;
        for (const auto& [key, values] : strs_map)
        {
            const int values_size = (int)values.size();
            std::vector<std::string> new_str(values_size);
            for (int j = 0; j < values_size; ++j)
            {
                new_str[j] = values[j];
            }

            new_strs[i++] = new_str;
        }
        
        return new_strs;
    }
};
