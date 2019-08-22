/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int n = x ^ y;
        int res = 0;
        while (n)
        {
            res += n & 1;
            n = n >> 1;
        }
        return res;
    }
};
