class Solution {
public:
    int maxPower(string s) {
        auto size = s.size();
        if (size == 0 || size == 1)
            return size;

        decltype(size) count = 1;
        decltype(size) maxCount = 0;
        for (decltype(size) i = 0, I = size - 1; i < I; ++i)
        {
            if (s[i] == s[i + 1])
                ++count;
            else
            {
                if (count > maxCount)
                    maxCount = count;

                count = 1;
            }

            if (i == I - 1 && count > maxCount)
            {
                return count;
            }
        }

        return maxCount;
    }
};
