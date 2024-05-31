#include <iostream>
#include <vector>

using namespace std;

// Time: O(n * logn)
// Memory: O(1)

/*
 Быстрая сортировка (quick sort) - используется метод перестановки относительно любого элемента массива (pivot), например последний элемент. Перестановка выполняется в отдельной функции (partition), в которой после сравнения с pivot массив делится на две группы: элементы меньше или равны переносятся влево. Функция partition вызывается рекурсивно для двух групп массива до тех пор, пока не останется только одно значение или пустой список значений.
 */

int Partition(std::vector<int>& nums, int left, int right)
{
    for (int i = left, pivot = nums[right]; i < right; ++i)
    {
        if (nums[i] <= pivot)
        {
            std::swap(nums[i], nums[left]);
            ++left;
        }
    }
    
    std::swap(nums[left], nums[right]);
    
    return left;
}

void QuickSort(std::vector<int>& nums, int left, int right)
{
    auto size = (int)nums.size();
    if (size <= 1)
        return;

    if (left < right)
    {
        int pivot = Partition(nums, left, right);
        QuickSort(nums, left, pivot - 1);
        QuickSort(nums, pivot + 1, right);
    }
}

int main(int argc, const char * argv[])
{
    std::vector<int> arr = {6, 2, 5, 1, 4, 3};
//    std::vector<int> arr = {1, 2, 3, 4, 5, 6};
    QuickSort(arr, 0, (int)arr.size() - 1); // Важный момент
    return 0;
}
