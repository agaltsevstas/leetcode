// Time: O(n)
// Memory: O(n)

class Solution {
public:
#if 0
    bool isValid(string str)
    {
        std::stack<char> stack;
        for (const auto& s : str)
        {
            if (s == '(' ||
                s == '{' ||
                s == '[')
            {
                stack.emplace(s);
            }
            else if (stack.empty())
            {
                return false;
            }
            else if (s == ')' && stack.top() == '(')
            {
                stack.pop();
            }
            else if (s == '}' && stack.top() == '{')
            {
                stack.pop();
            }
            else if (s == ']' && stack.top() == '[')
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
#endif
#if 1
bool isValid(string str)
    {
        std::unordered_map<char, char> braces =
        {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        std::stack<char> stack;
        for (const auto& s : str)
        {
            if (braces.contains(s))
                stack.push(s);
            else
            {
                if (stack.empty() || s != braces[stack.top()])
                    return false;
                
                stack.pop();
            }
        }

        return stack.empty();
    }
#endif
};
