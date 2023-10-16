// Time: O(n)
// Memory: O(n)

class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        int size = (int)s.size();
        if (size != t.size())
            return false;

        std::unordered_map<char, char> s_map, t_map;
        for (int i = 0, I = s.size(); i < I; ++i)
        {
            auto s_it = s_map.find(s[i]);
            auto t_it = t_map.find(t[i]);

            if (s_it != s_map.end() && t_it != t_map.end())
            {
                if (s_it->first != t_it->second || s_it->second != t_it->first)
                    return false;
            }
            else if (s_it == s_map.end() &&
                     t_it == t_map.end())
            {
                s_map[s[i]] = t[i];
                t_map[t[i]] = s[i];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
