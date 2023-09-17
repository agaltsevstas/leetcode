// Time: O(n + k), где k - кол-во уникальных символов
// Memory: O(k), где k - кол-во уникальных символов

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int size = (int)s.size();
        if (size != (int)t.size() || size == 0)
            return false;
            
        // a-z - 97-122 в ASCII
        constexpr int map_size = 123;
        std::array<int, map_size> letter_map {}; // Обязательно инициализация! Иначе мусор

        for (int i = 0; i < size; ++i)
        {
            letter_map[(int)s[i]] += 1;
            letter_map[(int)t[i]] -= 1;
        }

        // Если палиндром, то вся map должна состоять из нулей
        for (int i = 97; i < map_size; ++i) // Не делаем обычное сравнение, нам нужно только 97-122
        {
            if (letter_map[i] != 0)
                return false;
        }

        return true;
    }
};
