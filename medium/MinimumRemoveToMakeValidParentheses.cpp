// Time: O(n)
// Memory: O(n)

class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        std::stack<int> stack;
        for (int i = 0; i < s.size();)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else if (s[i] == ')')
            {
                if (stack.empty())
                {
                    s.erase(s.begin() + i);
                    continue;
                }
                else
                {
                    stack.pop();
                }
            }

             ++i;
        }
        
        while (!stack.empty())
        {
            s.erase(s.begin() + stack.top());
            stack.pop();
        }

        return s;
    }
};
