// Time: O(n)
// Memory: O(n)

class Solution
{
public:
    bool checkValidString(string str)
    {
        std::stack<int> stack;
        std::stack<int> stars;

        for (int i = 0, I = (int)str.size(); i < I; ++i)
        {
            if (str[i] == '*')
                stars.push(i);
            else if (str[i] == '(')
                stack.push(i);
            else if (str[i] == ')')
            {
                if(!stack.empty())
                    stack.pop();
                else if (!stars.empty())
                    stars.pop();
                else
                    return false;
            }
        }

        while (!stack.empty() && !stars.empty() && stars.top() > stack.top())
        {
            stack.pop();
            stars.pop();
        }

        return stack.empty();
    }
};
