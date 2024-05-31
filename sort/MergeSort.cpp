#include <iostream>
#include <vector>

using namespace std;

// Time: O(n * logn)
// Memory: O(n)

/*
 Сортировка слиянием (merge sort) - используется принцип «разделяй и властвуй» (split and merge), заключающийся в рекурсивном разбиении массива на подмассивы (используется деление на 2) до тех пор, пока кол-во элементов в подмассиве не станет равное 1. Потом эти подмассивы склеиваются и сортируются в единый массив, для используется дополнительная память.
 */

void Merge(std::vector<int>& nums, int left, int mid, int right)
{
    int left_point = left;
    int right_point = mid + 1; // Важный момент

    std::vector<int> sort_nums(right - left + 1); // Важный момент
    int i = 0;
    while (left_point <= mid && right_point <= right)
    {
        if (nums[left_point] > nums[right_point])
        {
            sort_nums[i++] = nums[right_point];
            ++right_point;
        }
        else
        {
            sort_nums[i++] = nums[left_point];
            ++left_point;
        }
    }

    while (left_point <= mid)
    {
        sort_nums[i++] = nums[left_point];
        ++left_point;
    }

    while (right_point <= right)
    {
        sort_nums[i++] = nums[right_point];
        ++right_point;
    }

    for (i = 0; i < sort_nums.size(); ++i)
    {
        nums[left++] = sort_nums[i];
    }
}

void MergeSort(std::vector<int>& nums, int left, int right)
{
    auto size = (int)nums.size();
    if (size <= 1)
        return;

    int mid = (right + left) / 2; // Важный момент! ищем середину 3 и 5 - это 4
    if (left < right)
    {
        MergeSort(nums, left, mid); // left
        MergeSort(nums, mid + 1, right); // right, Важный момент
        Merge(nums, left, mid, right);
    }
}

int main(int argc, const char * argv[])
{
    vector<int> arr = {5, 4, 3, 2, 1};
    MergeSort(arr, 0, (int)arr.size() - 1); // Важный момент
    return 0;
}
