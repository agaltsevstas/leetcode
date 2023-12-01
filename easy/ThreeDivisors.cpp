class Solution {
public:
    // 1 Способ: через корень
    // Time: O(sqrt(n)), где n - число
    // Memory: O(1)
#if 0
    bool isThree(int n)
    {
        if (n <= 2)
            return false;

        auto isPrime = [](int n)->bool
        {
            for (int i = 2, I = int(std::sqrt(n)) + 1; i < I; ++i)
            {
                if (n % i == 0)
                    return false;
            }
            return true;
        };

        // число будет иметь 3 делителя только в том случае
        // если оно получено возведением в квадрат 2 простых чисел
        return (int)std::pow(std::sqrt(n), 2) == n && isPrime((int)std::sqrt(n));
    }
#endif

    // 2 Способ: через перебор
    // Time: O(n), где n - число
    // Memory: O(1)
    bool isThree(int n)
    {
        if (n <= 2)
            return false;

        constexpr int divisor = 3;
        int count = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (n % i == 0)
                ++count;

            if (count > divisor)
                return false;
        }

        return count == divisor;
    }
};
