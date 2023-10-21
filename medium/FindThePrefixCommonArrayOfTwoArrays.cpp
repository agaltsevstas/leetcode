class Solution {
public:

    // Time: O(n^2)
    // Memory: O(n)
    /*
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b)
    {
        std::unordered_set<int> set;
        std::vector<int> result(size);
        for (int i = 0; i < size; ++i)
        {
            set.insert(a[i]);
            for (int j = 0; j <= i; ++j)
            {
                if (set.contains(b[j]))
                    ++result[i];
            }

            result[i];
        }

        return result;
    }
    */

    // Time: O(n^2)
    // Memory: O(n)
    /*
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b)
    {
        int size = (int)a.size();
        if (size != b.size())
            return {};

        std::vector<int> result(size);
        std::vector<bool> a_vec(size, false), b_vec(size, false);
        for (int i = 0; i < size; ++i)
        {
            a_vec[a[i] - 1] = b_vec[b[i] - 1] = true;
            for (int j = 0; j < size; ++j)
            {
                if (a_vec[j] && b_vec[j])
                    ++result[i];
            }
        }

        return result;
    }
    */

    // Time: O(n)
    // Memory: O(n)
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b)
    {
        int size = (int)a.size();
        if (size != b.size())
            return {};

        constexpr uintmax_t number = 1;
        uintmax_t a_bits = 0, b_bits = 0;
        std::vector<int> result(size, 0);
        for (int i = 0; i < size; ++i)
        {
            a_bits |= number << (a[i] - 1);
            b_bits |= number << (b[i] - 1);

            uintmax_t bits = a_bits & b_bits;
            while (bits != 0)
            {
                result[i] += bits % 2;
                bits /= 2;
            }
        }

        return result;
    }
};
