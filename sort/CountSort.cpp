#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Time: O(n)
// Memory: O(n)

std::vector<int> CountSort(std::vector<int>& nums)
{
    auto size = nums.size();
    for (int i = 0; i < size; ++i)
    {
        bool isSwap = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                isSwap = true;
            }
        }
        
        if (!isSwap)
        {
            break;
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
