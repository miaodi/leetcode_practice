/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            res += n % 2;
            n /= 2;
        }
        return res;
    }
};
