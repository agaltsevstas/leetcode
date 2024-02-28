// Time: O(n)
// Memory: O(n)

class Solution
{
    std::map<char, int> operations
    {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
        {'u', 3}
    };

private:
    void prevCalculate()
    {
        const char operation = _operations.top();
        _operations.pop();

        int result = 0;
        if (operation == 'u')
        {
            result = -_numbers.top();
            _numbers.pop();
        }
        else
        {
            const int number2 = _numbers.top();
            _numbers.pop();
            const int number1 = _numbers.top();
            _numbers.pop();
            
            if (operation == '+')
                result = number1 + number2;
            else if (operation == '-')
                result = number1 - number2;
            else if (operation == '*')
                result = number1 * number2;
            else if (operation == '/')
                result = number1 / number2;
        }

        _numbers.push(result);
    }

public:
    int calculate(std::string s)
    {
        const int size = (int)s.size();
        bool unary = true;
        
        int i = 0;
        while (i < size)
        {
            if (unary && s[i] == '-')
            {
                s[i] = 'u';
            }
            if (std::isdigit(s[i]))
            {
                int number = 0; // может быть составное число
                while (i < size && std::isdigit(s[i]))
                {
                    number = number * 10 + (s[i] - '0'); // приводит к int
                    ++i;
                }
                --i;
                _numbers.push(number);
                unary = false;
            }
            else if (s[i] == '(')
            {
                _operations.push(s[i]);
                unary = true;
            }
            else if (s[i] == ')')
            {
                while (_operations.top() != '(')
                    prevCalculate();
                
                _operations.pop();
                unary = false;
            }
            else if (operations.contains(s[i]))
            {
                while (!_operations.empty() && _operations.top() != '(' &&
                       operations[_operations.top()] >= operations[s[i]])
                {
                    prevCalculate();
                }

                _operations.push(s[i]);
                unary = true;
            }
            
            ++i;
        }

        while (!_operations.empty()) // могут остаться операции
            prevCalculate();

        return _numbers.top();
    }

private:
    std::stack<char> _operations;
    std::stack<int> _numbers;
};
