// Time: O(n)
// Memory: O(1)
/*
1. Сканируйте массив справа налево, пока не будет найден элемент, меньший, чем индекс справа. Обозначьте индекс такого элемента как index.
2. Снова просканируйте массив справа налево, пока не будет найден элемент, который больше элемента, найденного на предыдущем шаге. Обозначьте индекс таких элементов как j.
3. Поменяйте местами два элемента по индексам index и j.
4. Теперь переверните массив от индекса index + 1 до конца массива.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) // Ищем индекс index1, max - 1
    {
        const int size = (int)nums.size();
        int index = -1;
        
        for (int i = size - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            std::ranges::reverse(nums);
            return;
        }

        int j = size - 1;
        for(int i = size - 1; i > index; --i) // Ищем index2, индекс max
        {
            if (nums[i] > nums[index])
            {
                j = i;
                break;
            }
        }

        std::swap(nums[index], nums[j]); // swap (max, max - 1)
        std::reverse(nums.begin() + index + 1, nums.end()); // reverse(nums.begin() + index1 + 1, nums.end())
    }
};
