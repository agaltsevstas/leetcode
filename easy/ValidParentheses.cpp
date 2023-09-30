// Time: O(n)
// Memory: O(n)

class Solution {
public:
    bool isValid(string s)
    {
        std::stack<char> stack;
        for (const auto& c: s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else if (stack.empty())
            {
                return false;
            }
            else if (stack.top() == '(' && c == ')' ||
                     stack.top() == '{' && c == '}' ||
                     stack.top() == '[' && c == ']')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }

        return stack.empty();
    }
};
