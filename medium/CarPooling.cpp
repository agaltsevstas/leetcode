// Time: O(nlogn)
// Memory: O(n)

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        auto size = trips.size();
        vector<vector<int>> points(size * 2);
        for (decltype(size) i = 0, j = 0; i < size; ++i)
        {
            points[j++] = {trips[i][1], trips[i][0]};
            points[j++] = {trips[i][2], -trips[i][0]};
        }

        std::sort(points.begin(), points.end(), [](const auto& first, const auto& second)
        {
            // Обязательно: условие должно возвращать true, иначе false. Если поменять местами, то будет ошибка
            if (first.front() < second.front())
                return true;
            else if (first.front() == second.front() && first.back() < second.back())
                return true;

            return false;
        });

        int max = 0, sum = 0;
        for (const auto& point : points)
        {
            sum += point.back();
            max = std::max(max, sum);
            if (max > capacity)
                return false;
        }

        return true;
    }
};
