// Time: (2k + (n-k)logn) -> (nlogn)
// Memory: O(k)

class Compare
{
public:
    inline bool operator() (const std::vector<int>& lhs, const std::vector<int>& rhs) const noexcept
    {
        auto lhs_dist = std::sqrt(std::pow(lhs.front(), 2) + std::pow(lhs.back(), 2));
        auto rhs_dist = std::sqrt(std::pow(rhs.front(), 2) + std::pow(rhs.back(), 2));

        return lhs_dist < rhs_dist;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> heap;
    
        for (int i = 0; i < k; ++i)
        {
            heap.push(points[i]);
        }
        
        const Compare compare;
        for (int i = k, I = (int)points.size(); i < I; ++i)
        {
            if (compare(points[i], heap.top()))
            {
                heap.pop();
                heap.push(points[i]);
            }
        }
        
        const int heap_size = (int)heap.size();
        std::vector<std::vector<int>> result(heap_size);
        
        for (int i = 0; i < heap_size; ++i)
        {
            result[i] = std::move(heap.top());
            heap.pop();
        }
        
        return result;
    }
};
