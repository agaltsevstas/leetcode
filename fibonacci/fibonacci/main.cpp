#include <iostream>

/*
 Факториал - последовательность, в которой первые два числа равны 0 и 1, а каждое последующее число равно сумме двух предыдущих чисел.
 Пример: 6 = 0, 1, 1, 2, 3, 5, 8
 */

namespace runtime
{
    namespace recursion
    {
        int fibonacci(int n)
        {
            if (n <= 1)
                return n;

            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    namespace without_recursion
    {
        int fibonacci(int n)
        {
            if (n <= 1)
                return n;
            
            int first = 0, second = 1;
            --n;
            while (--n > 0)
            {
                int tmp = second;
                second += first;
                first = tmp;
            }
            
            return first + second;
        }
    }
}

namespace compile_time
{
    namespace CONSTEXPR
    {
        constexpr int fibonacci(int n)
        {
            if (n <= 1)
                return n;

            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    namespace CONSTEVAL
    {
        consteval int fibonacci(int n)
        {
            if (n <= 1)
                return n;

            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    namespace TEMPLATE
    {
        template<unsigned int N>
        struct Fibonacci
        {
            static constexpr unsigned int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
        };

        template<>
        struct Fibonacci<0>
        {
            static constexpr unsigned int value = 0;
        };

        template<>
        struct Fibonacci<1>
        {
            static constexpr unsigned int value = 1;
        };
    }
}

int main()
{
    /// Runtime - вычисление на этапе исполнения
    {
        using namespace runtime;
        
        [[maybe_unused]] auto result1 = recursion::fibonacci(6);
        [[maybe_unused]] auto result2 = without_recursion::fibonacci(6);
    }
    /// Compile time - вычисление на этапе компиляции
    {
        using namespace compile_time;
        /// C++17: constexpr -  если значение хотя бы одного аргумента не будет известен на этапе компиляции, то функция будет запущена в runtime. Аргументы функций не могут быть constexpr. Имеет характеристики inline.
        {
            int number = 6;
            // Runtime
            [[maybe_unused]] auto result1 = CONSTEXPR::fibonacci(number);
            // Complie: переменная, которая должна быть известна вовремя компиляции использоваться со статическими данными.
            [[maybe_unused]] constexpr auto result2 = CONSTEXPR::fibonacci(6);
        }
        /// C++20: consteval - функция, которые вычисляется только во время компиляции (C++20). Имеет характеристики inline.
        {
            [[maybe_unused]] auto result = CONSTEVAL::fibonacci(6);
        }
        /// Templates - шаблоны
        {
            [[maybe_unused]] auto result = TEMPLATE::Fibonacci<6>::value;
        }
    }
    return 0;
}
