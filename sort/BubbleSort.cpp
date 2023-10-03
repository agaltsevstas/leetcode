#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Time: O(n^2)
// Memory: O(1)

std::vector<int> BubbleSort(std::vector<int>& nums)
{
    auto size = nums.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
    return nums;
}

int main(int argc, const char * argv[])
{
    std::vector<int> nums = {5,2,3,1};
    auto result = BubbleSort(nums);
    return 0;
}
