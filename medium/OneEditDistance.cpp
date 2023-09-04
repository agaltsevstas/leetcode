// Time: O(n)
// Memory: O(1)

// https://www.lintcode.com/problem/640/

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        int size_s = s.size();
        int size_t = t.size();
        if (std::abs(size_s - size_t) > 1)
            return false;

        int s_index = 0;
        int t_index = 0;

        bool used_operation = false;
        while (s_index <= size_s &&
               t_index <= size_t)
        {
            if (s[s_index] == t[t_index])
            {
                ++s_index;
                ++t_index;
            }
            else if (used_operation)
            {
                used_operation = false;
                break;
            }
            else
            {
                if (s_index == size_s - 1 ||
                    t_index == size_t - 1)
                {
                    used_operation = !used_operation;
                    break;
                }
                else if (size_s > size_t)
                    ++s_index;
                else if (size_t > size_s)
                    ++t_index;
                else
                {
                    ++s_index;
                    ++t_index;
                }
                
                used_operation = true;
            }
        }

        return used_operation;
    }
};
