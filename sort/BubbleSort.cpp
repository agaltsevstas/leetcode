#include <iostream>
#include <vector>


// Time: O(n^2)
// Memory: O(1)
std::vector<int> BubbleSort(std::vector<int>& nums)
{
    for (int i = 0, I = (int)nums.size(); i < I; ++i)
    {
        for (int j = 0; j < I - 1; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
    
    return nums;
}

// Time: O(n^2)/2 -> O(n^2)
// Memory: O(1)
std::vector<int> OptimizedBubbleSort(std::vector<int>& nums)
{
    for (int i = 0, I = (int)nums.size(); i < I; ++i)
    {
        bool isSwap = false;
        for (int j = 0; j < I - i - 1; ++j)
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

int main()
{
    std::vector<int> nums = {5,2,3,1};
    auto bubbleSort_result1 = BubbleSort(nums);
    auto bubbleSort_result2 = BubbleSort(nums);
    nums = {5,2,3,1};
    auto optimizedBubbleSort_result1 = OptimizedBubbleSort(nums);
    auto optimizedBubbleSort_result2 = OptimizedBubbleSort(nums);
    
    return 0;
}
