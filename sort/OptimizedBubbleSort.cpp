#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Time: O(n^2)
// Memory: O(1)

std::vector<int> OptimizedBubbleSort(std::vector<int>& nums)
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
    std::vector<int> nums = {2,1,3,4,5};
    auto result = OptimizedBubbleSort(nums);
    return 0;
}
