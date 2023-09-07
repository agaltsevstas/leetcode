// Time: O(n)
// Memory: O(n)

// https://www.codingninjas.com/studio/problems/replace-spaces_1172172

#include <bits/stdc++.h>
string replaceSpaces(string &str){
    int size = str.size();
    std::vector<int> space_indexes(100);
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (std::isspace(str[i]) && i != size - 1)
        {
            space_indexes[i] = 1;
            ++count;
        }
    }

    string word = "@40";
    string new_str(size - count + count * word.size(), '_');
    for (int i = 0, j = 0; i < size; ++i)
    {
        if (space_indexes[i] == 1)
        {
            for (const auto &letter : word)
            {
                new_str[j] = letter;
                ++j;
            }
        }
        else
        {
            new_str[j] = str[i];
            ++j;
        }
    }

    return new_str;
}
