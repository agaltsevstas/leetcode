// Time: O(n)
// Memory: O(n)

class Solution
{
public:
#if 1
    std::string reverseWords(std::string str)
    {
        std::stack<std::string> stack;
        std::string result;
        
        for (int i = 0, I = (int)str.size(); i < I; ++i)
        {
            if (str[i] != ' ')
            {
                result += str[i];
            }
            else if (!result.empty())
            {
                stack.push(result);
                result.clear();
            }
        }
        
        if (!result.empty())
        {
            stack.push(result);
            result.clear();
        }
        
        while (!stack.empty())
        {
            result += stack.top() + ' ';
            stack.pop();
        }
        
        if (result.back() == ' ')
            result.pop_back();
        
        return result;
    }
#endif
#if 0
    std::string reverseWords(std::string str)
    {
        int left = -1;
        int right = - 1;
        std::string result;
        
        for (int i = (int)str.size() - 1; i >= 0; --i)
        {
            if (str[i] == ' ' && right != -1)
            {
                auto word = str.substr(left, right - left + 1);
                result += result.empty() ? word : " " + word;
                right = -1;
            }
            else if (str[i] != ' ')
            {
                left = i;
                
                if (right == -1)
                    right = i;
                if (i == 0) // "e two three ", "EPY2giL"
                {
                    auto word = str.substr(left, right - left + 1);
                    result += result.empty() ? word : " " + word;
                }
            }
        }

        return result;
    }
#endif
};
