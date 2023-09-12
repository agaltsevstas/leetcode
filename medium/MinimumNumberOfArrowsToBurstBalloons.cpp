// Time: O(nlogn)
// Memory: O(n)

class Solution {
public:

    bool IsMerge(const vector<int>& first, const vector<int>& second)
    {
        return std::max(first.front(), second.front()) <= std::min(first.back(), second.back());
    }

    vector<int> ToMerge(const vector<int>& first, const vector<int>& second)
    {
        return {std::max(first.front(), second.front()), std::min(first.back(), second.back())};
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int size = (int)points.size();
        if (size <= 1)
            return size;

        std::sort(points.begin(), points.end(), [](const auto& first, const auto& second)
        {
            // Обязательно: условие должно возвращать true, иначе false. Если поменять местами, то будет ошибка
            if (first.front() < second.front())
                return true;
            else if (first.front() == second.front() && first.back() <= second.back())
                return true;

            return false;
        });

        int count = 1;
        vector<int> merged = { points.front() };
        for (decltype(size) i = 1; i < size; ++i)
        {
            if (IsMerge(merged, points[i]))
            {
                merged = ToMerge(merged, points[i]);
            }
            else
            {
                merged = points[i];
                ++count;
            }
        }
        
        return count;
    }
};
