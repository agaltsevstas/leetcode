// Time: O(n)
// Memory: O(1)

class Solution {
public:
    std::string reverseWords(std::string s)
    {
        std::stack<string> stack;
        std::string str;
        for (int i = 0, I = s.size(); i < I; ++i)
        {
            if (s[i] != ' ')
            {
                str += s[i];
            }
            else if (!str.empty())
            {
                stack.push(str);
                str.clear();
            }
        }
        
        if (!str.empty())
        {
            stack.push(str);
            str.clear();
        }

        if (stack.empty())
            return s;

        while (!stack.empty())
        {
            str += stack.top() + " ";
            stack.pop();
        }

        if (str.back() == ' ')
            str.pop_back();

        return str;
    }
};
