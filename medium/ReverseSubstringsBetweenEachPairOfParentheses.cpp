// Time: O(n)
// Memory: O(n)

class Solution
{
public:
    string reverseParentheses(string s)
    {
        std::stack<int> stack;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == '(')
                stack.push(i);
            else if (s[i] == ')')
            {
                std::reverse(s.begin() + stack.top() + 1, s.begin() + i);
                s.erase(s.begin() + i);
                s.erase(s.begin() + stack.top());
                stack.pop();
                i -= 2;
            }

            ++i;
        }

        return s;
    }
};
