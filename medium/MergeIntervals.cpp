// Time: O(nlogn)
// Memory: O(n)

class Solution {
public:

    bool IsMerge(vector<int>& first, vector<int>& second)
    {
        return std::max(first.front(), second.front()) <= std::min(first.back(), second.back());
    }

    vector<int> ToMerge(vector<int>& first, vector<int>& second)
    {
        return { std::min(first.front(), second.front()), std::max(first.back(), second.back()) };
    }

    void Sort(vector<vector<int>>& intervals)
    {
        for (size_t i = 0, I = intervals.size(); i < I; ++i)
        {
            for (size_t j = 0; j < I - i - 1; ++j)
            {
                if (intervals[j].front() > intervals[j + 1].front())
                    swap(intervals[j], intervals[j + 1]);
            }
        }
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto size = intervals.size();
        if (size <= 1)
            return intervals;

        Sort(intervals);

        std::vector<std::vector<int>> result = {intervals.front()};
        for (size_t i = 1; i < size; ++i)
        {
            if (IsMerge(result.back(), intervals[i]))
            {
                result.back() = ToMerge(result.back(), intervals[i]);
            }
            else
            {
                result.emplace_back(intervals[i]);
            }
        }
        
        return result;
    }
};
