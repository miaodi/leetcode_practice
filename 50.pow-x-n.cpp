/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
class Solution
{
public:
    // // simple one TLE
    // double myPow(double x, int n)
    // {
    //     if (n == 0)
    //         return 1;
    //     if (n < 0)
    //     {
    //         x = 1.0 / x;
    //         n = -n;
    //     }
    //     double res = 1;
    //     for (int i = 0; i < n; i++)
    //     {
    //         res *= x;
    //     }
    //     return res;
    // }
    // recursive
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1.0 / x;
        auto tmp = myPow(x, n / 2);
        return tmp * tmp * myPow(x, n % 2);
    }
};
