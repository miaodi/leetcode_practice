/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int res = 0;
        while (n)
        {
            res += n % 2;
            n /= 2;
        }
        return res == 1;
    }
};
