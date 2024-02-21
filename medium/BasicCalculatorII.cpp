// Time: O(n)
// Memory: O(n)

class Solution
{
    std::map<char, int> operations =
        {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
        };
private:
    void prevCalculate()
    {
        const int number2 = _numbers.top();
        _numbers.pop();
        const int number1 = _numbers.top();
        _numbers.pop();
        const char operation = _operations.top();
        _operations.pop();

        int result = 0;
        if (operation == '+')
            result = number1 + number2;
        else if (operation == '-')
            result = number1 - number2;
        else if (operation == '*')
            result = number1 * number2;
        else if (operation == '/')
            result = number1 / number2;

        _numbers.push(result);
    }

public:
    int calculate(string s)
    {
        int number = 0; // может быть составное число
        s += '.'; // если строка заканчивается числом
        for (int i = 0, I = (int)s.size(); i < I; ++i)
        {
            const auto& letter = s[i];
            if (letter == ' ')
                continue;
            else if (letter == '.')
                _numbers.emplace(number);
            else if (std::isdigit(letter))
                number = number * 10 + (letter - '0'); // приводит к int
            else
            {
                _numbers.emplace(number);
                number = 0;

                while (!_operations.empty() &&
                    operations[_operations.top()] >= operations[letter])
                {
                    prevCalculate();
                }
                    
                _operations.push(letter);
            }
        }

        while (!_operations.empty()) // могут остаться операции
            prevCalculate();

        return _numbers.top();
    }

private:
    std::stack<int> _numbers;
    std::stack<char> _operations;
};
