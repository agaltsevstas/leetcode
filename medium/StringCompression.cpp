// Time: O(n)
// Memory: O(n)

class Solution {
public:
    int compress(vector<char>& chars)
    {
        const int size = chars.size();
        int prev = 0;
        int next = 1;
        int count = 1;

        std::string result; // лучше не использовать vector<char>, т.к. перевести число более 1 знака -> char сложно
        while (next <= size)
        {
            if (next == size)
            {
                result += chars[prev];
                if (count > 1)
                    result += std::to_string(count);
                    // result += count + '0'; // число более 1 знака неверно конвертируется
            }
            else if (chars[prev] == chars[next])
            {
                ++count;
            }
            else
            {
                result += chars[prev];
                if (count > 1)
                    result += std::to_string(count);
                    // result += count + '0'; // число более 1 знака неверно конвертируется

                count = 1;
                prev = next;
            }

            ++next;
        }

        chars = std::vector<char>(result.begin(), result.end());
        return chars.size();
    }
};
