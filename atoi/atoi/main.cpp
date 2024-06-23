#include <iostream>
#include <string>

size_t str_len(const char *str)
{
    return (*str) ? str_len(++str) + 1 : 0;
}

int AtoI(const char* str)
{
    int number = 0;
    for (size_t i = 0, I = str_len(str); i < I; ++i)
    {
        if (str[i] < '0' || str[i] > '9')
            throw std::logic_error(std::string("Неверный аргумент: ") + str[i]);
        number = number * 10 + str[i] - '0';
    }
    
    return number;
}

int main()
{
    [[maybe_unused]] auto result = AtoI("123");
    try
    {
        [[maybe_unused]] auto result = AtoI("12a3");
    }
    catch (const std::logic_error& exception)
    {
        std::cout << exception.what() << std::endl;
    }
    
    return 0;
}
