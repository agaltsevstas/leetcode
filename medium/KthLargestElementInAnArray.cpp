// Time: O(k + (n - k)logn)
// Memory: O(k)
// Куча на минимум, но храним максимальные элементы

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<>> heap; // min heap

        for (int i = 0; i < k; ++i)
        {
            heap.push(nums[i]);
        }

        for (int i = k, I = nums.size(); i < I; ++i)
        {
            if (nums[i] > heap.top())
            {
                heap.pop();
                heap.push(nums[i]);
            }
        }

        return heap.top();
    }
};
