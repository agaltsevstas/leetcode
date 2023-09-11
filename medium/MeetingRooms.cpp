// Time: O(logn)
// Memory: O(2n) -> O(n)

// Долгая сортировка
void Sort(vector<vector<int>>& points)
{
    for (size_t i = 0, I = points.size(); i < I; ++i)
    {
        for (size_t j = 0; j < I - i - 1; ++j)
        {
            if (points[j].front() > points[j + 1].front())
            {
                swap(points[j], points[j + 1]);
            }
            // Случай: [1, -1] и [1, 1]
            else if (points[j].front() == points[j + 1].front() &&
                     points[j].back() > points[j + 1].back())
                    {
                         swap(points[j], points[j + 1]);
                    }
        }
    }
}

int Solution::solve(vector<vector<int>> &nums)
{
    auto size = nums.size();
    vector<vector<int>> points(size * 2);
    for (int i = 0, j = 0; i < size; ++i)
    {
        points[j++] = {nums[i].front(), 1};
        points[j++] = {nums[i].back(), -1};
    }
    
    std::sort(points.begin(), points.end(), [](const auto& first, const auto& second)
    {
        if (first.front() > second.front())
        {
            return false;
        }
        // Случай: [1, -1] и [1, 1]
        else if (first.front() == second.front() && first.back() > second.back())
        {
            return false;
        }
        
        return true;
    });
    
    int max = 0, sum = 0;
    for (const auto& point : points)
    {
        sum += point.back();
        max = std::max(max, sum);
    }
    
    return max;
}
