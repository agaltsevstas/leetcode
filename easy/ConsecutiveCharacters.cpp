// Time: O(n)
// Memory: O(1)

class Solution {
public:
    int maxPower(string s)
    {
        const int size = (int)s.size();
        int prev = -1;
        int cur = 0;
        int next = 1;
        int max = 1;

        while (next < size)
        {
            if (s[cur] != s[next])
                prev = cur;

            ++cur;
            ++next;

            // при (next == size) выйдет из условия, "cc" - не подсчитает, поэтому обрабатываем этот случай здесь
            max = std::max(max, next - (prev + 1)); // (prev + 1) - нужно при prev == -1 дотянуть до 0
        }

        return max;
    }
};
