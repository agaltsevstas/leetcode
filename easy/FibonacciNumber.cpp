class Solution {
public:
    int fib(int n) {
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
    
    int fib(int n) {
        if (n <= 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
