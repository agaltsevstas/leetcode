/*
 1 Способ: std::array
 n - кол-во слов, m - макс кол-во букв, k - кол-во уникальных символов
 Time: O(n * m + k)
 Memory: O(n * m + k)
*/

/*
 2 Способ: std::string
 n - кол-во слов, m - макс кол-во букв, k - кол-во уникальных символов
 Time: O(n * mlogm + k)
 Memory: O(n * m + k)
*/

class Solution
{
public:
#if 1
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        constexpr int key_size = 26; // a-z - 97-122 в ASCII
        std::map<std::array<int, key_size>, std::vector<std::string>> strs_map;
        for (const auto& str : strs)
        {
            std::array<int, key_size> key {}; // Обязательно инициализация! Иначе мусор
            for (const auto& letter : str)
            {
                key[letter - 'a'] += 1;
            }

            strs_map[key].emplace_back(str);
        }

        std::vector<std::vector<string>> result(strs_map.size());
        for (int i = 0; const auto& [_, values] : strs_map)
        {
            result[i].reserve(values.size());
            for (const auto& value: values)
            {
                result[i].emplace_back(value);
            }
            ++i;
        }

        return result;
    }
#endif

#if 0
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        if (strs.empty())
            return {};

        std::map<std::string, std::vector<std::string>> strs_map;
        for (const auto& str : strs)
        {
            auto str_copy = str;
            std::ranges::sort(str_copy);
            strs_map[str_copy].emplace_back(str);
        }

        std::vector<std::vector<string>> result (strs_map.size());
        for (int i = 0; const auto& [_, values] : strs_map)
        {
            result[i].reserve(values.size());
            for (const auto& value: values)
            {
                result[i].emplace_back(value);
            }
            ++i;
        }

        return result;
    }
#endif
};
