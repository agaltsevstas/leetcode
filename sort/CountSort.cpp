#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Time: O(n)
// Memory: O(n)

std::vector<int> CountSort(std::vector<int>& nums)
{
    int offset = 5 * std::pow(10, 4);
    std::vector<int> nums_map(offset * 2 + 1, 0);
    for (const auto& num: nums)
    {
        nums_map[num + offset] += 1;
    }

    std::vector<int> result;
    for (size_t i = 0, I = nums_map.size(); i < I; ++i)
    {
        if (nums_map[i] >= 1)
        {
            for (int j = 0; j < nums_map[i]; ++j)
            {
                result.emplace_back(i - offset);
            }
        }
    }

    return result;
}

int main(int argc, const char * argv[])
{
    std::vector<int> nums = {5,2,3,1};
    auto result = BubbleSort(nums);
    return 0;
}
