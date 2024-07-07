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
    bool isOneEditDistance(string &s, string &t)
    {
        int str_size = (int)str.size();
        int mask_size = (int)mask.size();
        int s = 0;
        int m = 0;
        if (std::abs(str_size - mask_size) > 1)
            return false;

        bool canOperation = false;
        while (m < mask_size && s < str_size)
        {
            if (mask[m] == str[s])
            {
                ++m;
                ++s;
            }
            else
            {
                if (canOperation) // если уже применена операция (вставки/удаления/изменение), то это уже 2 операции, что противоречит условию
                {
                    return false;
                }
                /*
                 "bcde"
                 "ccde"
                 */
                else if (mask_size == str_size) // изменили символ на другой символ в подстроке
                {
                    ++m;
                    ++s;
                    canOperation = true;
                }
                /*
                 "bcde"
                 "abcde"
                 */
                else if (mask_size > str_size) // если добавили символ к подстроке
                {
                    ++m;
                    canOperation = true;
                }
                /*
                 "abcde"
                 "bcde"
                 */
                else if (str_size > mask_size) // если удалили символ в строке
                {
                    ++s;
                    canOperation = true;
                }
            }
        }

        /*
        Проверка:
        "ad" "a"
        */
        if (m < mask_size)
            canOperation = !canOperation;
        else if (s < str_size)
            canOperation = !canOperation;

        return canOperation;
    }
};
