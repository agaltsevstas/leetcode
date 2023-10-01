// Time: O(n)
// Memory: O(n)

class Solution {
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
