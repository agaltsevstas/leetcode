// Time: O(n)
// Memory: O(n)

class Solution
{
public:
    string removeDuplicateLetters(string str)
    {
        std::array<int, 26> symbols, used; // a-z - 97-122 в ASCII
        
        for (const auto& s : str) // count sort
            ++symbols[s - 'a'];

        std::string result;
        for (const auto& s : str)
        {
            --symbols[s - 'a'];
            if (used[s - 'a']++ > 0)
                continue;

            while (!result.empty() && result.back() > s && symbols[result.back() - 'a'] > 0)
            {
                used[result.back() - 'a'] = 0;
                result.pop_back();
            }

            result.push_back(s);
        }

        return result;
    }
};
