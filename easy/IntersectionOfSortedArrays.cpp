// Time: O(max(n, m))
// Memory: O(min(n, m))

// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    
    auto a_it = A.begin();
    auto b_it = B.begin();
    
    vector<int> result;
    while (a_it != A.end() &&
           b_it != B.end())
    {
        if (*a_it == *b_it)
        {
            result.emplace_back(*a_it);
            ++a_it;
            ++b_it;
        }
        else if (*a_it < *b_it)
        {
            ++a_it;
        }
        else if (*a_it > *b_it)
        {
            ++b_it;
        }
    }
    
    return result;
}
