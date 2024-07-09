// Time: O(n)
// Memory: O(n)

/*
Дан список температур по дням, все температуры разные.
Для каждого дня найти, через сколько дней станет теплее.
in: [73, 74, 75, 71, 69, 72, 76, 73]
out: [1 , 1 , 4 , 2 , 1 , 1 , 0 , 0]
                             76
             75
         74
     73                          73
                         72
                 71
                     69
Т.е. для каждого числа нужно найти первое большее значение справа.
Двигаемся слева->направо, а не справа->налево!
*/

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        auto size = temperatures.size();
        std::stack<std::pair<int, int>> stack;
        stack.push({0, temperatures[0]});
        std::vector<int> result(size, 0);
        for (int i = 1; i < size; ++i)
        {
            while(!stack.empty())
            {
                if (temperatures[i] > stack.top().second)
                {
                    result[stack.top().first] = i - stack.top().first;
                    stack.pop();
                }
                else
                {
                    break;
                }
            }

            stack.push({i, temperatures[i]});
        }

        return result;
    }
};
