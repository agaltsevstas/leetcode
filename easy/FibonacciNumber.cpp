/* Чи́сла Фибона́ччи — элементы числовой последовательности, где сумма текущего значения равна двум предыдущим значениям
Числа:  0, 1, 1, 2, 3, 5, 8, 13, 21, 34
Индекс: 0, 1, 2, 3, 4, 5, 6, 7,  8,  9
                            fib(5)
                     /                \
               fib(4)                fib(3)
             /        \              /       \
         fib(3)      fib(2)         fib(2)   fib(1)
        /    \       /    \        /      \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /     \
fib(1) fib(0)
*/


class Solution
{
public:

// Рекурсия
// Time: O(2^n)
// Memory: O(n) - создается новый аргумент в функции
#if 0
    int fib(int n) // Передается индекс
    {
        if (n <= 1)
            return n; // return n - не может быть, т.к. может вернуть 0

        return fibonacci(n - 1) + fibonacci(n - 2);
    }
# endif

// Без рекурсии
// Time: O(n)
// Memory: O(n) - внутри цикла создается временная переменная
#if 1
    int fib(int n) // Передается индекс
    {
        if (n <= 1)
            return n; // return n - не может быть, т.к. может вернуть 0

        int first = 0, second = 1;
        while (--n > 1)
        {
            int tmp = second;
            second += first;
            first = tmp;
        }

        return first + second;
    }
# endif
};
