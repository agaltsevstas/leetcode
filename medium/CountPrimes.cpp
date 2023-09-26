// Time: O(nloglogn)
// Memory: O(n)

class Solution {
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;
        
        int count = 1;
        std::vector<bool> numbers(n + 1, true); // Обязательно +1, иначе при 5000000 переполнение
        for (int i = 2; i < n; ++i)
        {
            if (!numbers[i])
                continue;

            if (i % 2 != 0)
            {
                ++count;
            }
            
            auto j = std::pow(i, 2);
            while (j <= n)
            {
                numbers[j] = false;
                j += i;
            }
        }

        return count;
    }
};
