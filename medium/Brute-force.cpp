#include <iostream>
#include <string>

// Ozon: Brute-force
// n - длина массив, m - кол-во уникальных символов
// Time: O(n^m * (m + n))
// Memory: O(n^m)
std::string checkPassword(const std::string& password)
{
    int n = (int)password.size();
    constexpr int m = 4; // Кол-во уникальных символов
    std::array<char, m> unique = {'a', 'b', 'c', 'd'};
    
    for (int i = 0, I = std::pow(n, m); i < I; ++i)
    {
        std::string result(n, 'a');
        int j = m - 1;
        int count = i;
        while (count > 0)
        {
            int lastDigit = count % n;
            result[j] = unique[lastDigit];
            count /= n;
            j -=1;
        }
        
        if (result == password)
            return result;
    }
    
    return {};
}

int main ()
{
    std::string password = "accd";
    std::cout << "Password: " << checkPassword(password) << std::endl;
    return 0;
}
