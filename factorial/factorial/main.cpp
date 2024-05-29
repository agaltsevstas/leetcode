#include <iostream>

/*
 Факториал - произведение всех натуральных чисел от 1 до n включительно.
 Пример: 5! = 1 * 2 * 3 * 4 * 5 = 120
 */

namespace runtime
{
    int factorial(int n)
    {
        if (n == 0)
            return 1;
        
        return factorial(n - 1) * n;
    }
}

namespace compile_time
{
    namespace CONSTEXPR
    {
        constexpr int factorial(int n)
        {
            if (n == 0)
                return 1;
            
            return factorial(n - 1) * n;
        }
    }
    namespace CONSTEVAL
    {
        consteval int factorial(int n)
        {
            if (n == 0)
                return 1;
            
            return factorial(n - 1) * n;
        }
    }
    namespace TEMPLATE
    {
        template<unsigned int N>
        struct Factorial
        {
            static constexpr unsigned int value = N * Factorial<N-1>::value;
        };

        template<>
        struct Factorial<0>
        {
            static constexpr unsigned int value = 1;
        };
    }
}

int main()
{
    /*
     Факториал - произведение всех натуральных чисел от 1 до n включительно.
     Пример: 5 = 0, 1, 1, 2, 3, 5, 8
     */
    
    /// Runtime - вычисление на этапе исполнения
    {
        using namespace runtime;
        
        [[maybe_unused]] auto result = factorial(5);
    }
    /// Compile time - вычисление на этапе компиляции
    {
        using namespace compile_time;
        /// C++17: constexpr -  если значение хотя бы одного аргумента не будет известен на этапе компиляции, то функция будет запущена в runtime. Аргументы функций не могут быть constexpr. Имеет характеристики inline.
        {
            int number = 5;
            // Runtime
            [[maybe_unused]] auto result1 = CONSTEXPR::factorial(number);
            // Complie: переменная, которая должна быть известна вовремя компиляции использоваться со статическими данными.
            [[maybe_unused]] constexpr auto result2 = CONSTEXPR::factorial(5);
        }
        /// C++20: consteval - функция, которые вычисляется только во время компиляции (C++20). Имеет характеристики inline.
        {
            [[maybe_unused]] auto result = CONSTEVAL::factorial(5);
        }
        /// Templates - шаблоны
        {
            [[maybe_unused]] auto result = TEMPLATE::Factorial<5>::value;
        }
    }
    return 0;
}
