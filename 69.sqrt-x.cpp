/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
class Solution
{
public:
    int mySqrt(int x)
    {
        long l = 0;
        long r = x;
        while (l < r)
        {
            long mid = (l + r) / 2;
            if (mid * mid < x)
            {
                l = mid;
            }
            else if (mid * mid > x)
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
            if (r - l == 1)
                return r * r > x ? l : r;
        }
        return l;
    }
};
