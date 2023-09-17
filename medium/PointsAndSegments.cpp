#include <iostream>
#include <vector>
#include <map>

// n - число интервалов, k - число точек
// Time: O((n + k) * log(n + k))
// Memory: O(n + k)

/*
Дано n отрезков на числовой прямой и m точек на этой же прямой. Для каждой из данных точек определите, скольким отрезкам они принадлежат. Точка x считается принадлежащей отрезку с концами a и b , если выполняется двойное неравенство min ( a , b ) ≤ x ≤ max ( a , b ) .

Входные данные
Первая строка содержит два целых числа n (1 ≤ n ≤ 10 5 ) – число отрезков и m (1 ≤ m ≤ 10 5 ) – число точек. В следующих n строках по два целых числи a i и b i – координаты концов соответствующего отрезка(например, может быть пара 5 2). В последней строке m целых чисел – координаты точек. Все числа по модулю не превосходят 10 9
 */

// https://informatics.msk.ru/mod/statements/view.php?chapterid=112542#1

std::vector<int> PointsAndSegments(const std::vector<std::vector<int>>& iPoints)
{
    if (iPoints.size() < 3)
        return {};
    
    const auto& pointsAndSegments = iPoints.front();
    if (pointsAndSegments.size() < 2)
        return {};
    
    const auto& segments_count = pointsAndSegments.front();
    const auto& points_count = pointsAndSegments.back();
    
    std::vector<std::vector<int>> new_points(segments_count * 2 + points_count);
    int j = 0;
    for (int i = 0; i < segments_count; ++i)
    {
        new_points[j++] = {iPoints[i + 1].front(), +1};
        new_points[j++] = {iPoints[i + 1].back(), -1};
    }
    
    std::map<int, int> points_map; // Все числа по модулю не превосходят 10^9, проще завести map, чем count sort в качестве vector
    for (int i = 0; i < points_count; ++i)
    {
        new_points[j++] = {iPoints.back()[i], 0};
        points_map[iPoints.back()[i]] = i;
    }
    
    std::sort(new_points.begin(), new_points.end(), [](const auto& first, const auto& second)
    {
        if (first.front() < second.front())
            return true;
        else if (first.front() == second.front() && first.back() < second.back())
            return true;
        
        return false;
    });
    
    std::vector<int> result_points(points_count, 0);
    int sum = 0;
    for (int i = 0, I = (int)new_points.size(); i < I; ++i)
    {
        sum += new_points[i].back();
        if (new_points[i].back() == 0)
        {
            result_points[points_map.at(new_points[i].front())] = sum;
        }
    }

    return result_points;
}

int main(int argc, const char * argv[])
{
    std::vector<std::vector<int>> points1 = {{3, 2},
                                            {0, 5},
                                            {-3, 2},
                                            {7, 10},
                                            {1, 6}};
    
    std::vector<std::vector<int>> points2 = {{1, 3},
                                            {-10, 10},
                                            {-100, 100, 0}};
    
    auto result1 = PointsAndSegments(points1);
    auto result2 = PointsAndSegments(points2);
    return 0;
}
