// Time: O(n)
// Memory: O(n)

class Solution
{
public:
    std::string decodeString(std::string str)
    {
        std::stack<std::string> symbols;
        std::stack<int> numbers;
        std::string result;
        int number = 0;
        
        for (const auto& s : str)
        {
            if (std::isalpha(s))
            {
                result += s;
            }
            else if (std::isdigit(s))
            {
                number = number * 10 + s - '0';
            }
            else if (s == '[')
            {
                symbols.push(result);
                numbers.push(number);
                result.clear();
                number = 0;
            }
            else if (s == ']')
            {
                auto symbol = symbols.top();
                symbols.pop();
                auto num = numbers.top();
                numbers.pop();
                
                while (num-- > 0)
                    symbol += result;
                
                result = symbol;
            }
        }
        
        return result;
    }
};
