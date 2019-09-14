/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */
class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        return K * 2 >= (A.back() - A[0]) ? 0 : A.back() - A[0] - 2 * K;
    }
};
