// Time: O(n)
// Memory: O(1)

int Solution::solve(string A)
{
    int count = 0;
    for (const auto& c : A)
    {
        if (c == '(')
        {
            ++count;
        }
        else if (count == 0)
        {
            return 0;
        }
        else if (c == ')')
        {
            --count;
        }
    }
    
    return count == 0 ? 1 : 0;
}
