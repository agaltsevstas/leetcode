// Time: O(n)
// Memory: O(n)

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
    {
        vector<vector<int>> result;

        size_t first = 0;
        size_t second = 0;
        while (first < firstList.size() && second < secondList.size())
        {
            int max_left = std::max(firstList[first].front(), secondList[second].front());
            int min_right = std::min(firstList[first].back(), secondList[second].back());
            if (max_left <= min_right)
                result.push_back(std::vector<int>{max_left, min_right});

            if (firstList[first].back() < secondList[second].back())
                ++first;
            else if (firstList[first].back() > secondList[second].back())
                ++second;
            else
            {
                ++first;
                ++second;
            }
        }

        return result;
    }
};
