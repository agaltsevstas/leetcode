// Time: O(n)
// Memory: O(n)

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() == k)
            return "0";

        std::stack<char> stack;
        stack.push(num.front());
        for (int i = 1, I = (int)num.size(); i < I; ++i)
        {
            while (k > 0 && !stack.empty() && num[i] < stack.top()) // Добавляем меньшие числа
            {
                stack.pop();
                --k;
            }

            if (stack.empty() && num[i] == '0')
                continue;
            
            stack.push(num[i]);
        }

        while (!stack.empty() && k > 0) // если числа были в порядке возрастания, например: 112
        {
            stack.pop();
            --k;
        }

        std::string result(stack.size(), '0'); // Конструктор: инициализируем любым числом
        int i = stack.size() - 1;
        while (!stack.empty() && i >= 0) // Идем с конца в начало
        {
            result[i--] = stack.top();
            stack.pop();
        }

        if (result.empty()) // Например, num == 10, k == 1
            return "0";

        return result;
    }
};
