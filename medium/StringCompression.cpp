// Time: O(n)
// Memory: O(n)

class Solution {
public:
    int compress(vector<char>& chars) {
        auto size = chars.size();
        if (size == 0)
            return 0;
        else if (size == 1)
            return 1;
            
        char letter = chars.front();
        decltype(size) count = 1;
        std::string str;
        for (decltype(size) i = 1; i < size; ++i)
        {
            if (i == size - 1)
            {
                if (chars[i] == letter)
                {
                    str += letter;
                    str += std::to_string(++count);
                }
                else
                {
                    if (count == 1)
                        str += letter;
                    else
                    {
                        str += letter;
                        str += std::to_string(count);
                    }

                    str += chars[i];
                }
            }
            else
            {
                if (chars[i] == letter)
                {
                    ++count;
                }
                else
                {
                    if (count == 1)
                        str += letter;
                    else
                    {
                        str += letter;
                        str += std::to_string(count);
                    }

                    letter = chars[i];
                    count = 1;
                }
            }
        }

        chars = vector<char>(str.begin(), str.end());
        return chars.size();
    }
};
