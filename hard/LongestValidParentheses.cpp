// Time: O(n)
// Memory: O(n)

class Solution {
public:
    int longestValidParentheses(string s)
    {
        std::stack<int> stack;
        stack.push(-1);
        int max = 0;
        for (int i = 0, I = (int)s.size(); i < I; ++i)
        {
            if (s[i] == '(')
                stack.push(i);
            else if (s[i] == ')')
            {
                stack.pop();
                if (stack.empty())
                    stack.push(i);
                else
                    max = std::max(max, i - stack.top());
            }
        }

        return max;
    }
};
