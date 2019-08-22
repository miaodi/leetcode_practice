/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */
class Solution
{
    // unordered_map<int, int> m;

public:
    // int integerReplacement(int n)
    // {
    //     if (n == 1)
    //         return 0;
    //     if (m.find(n) == m.end())
    //     {
    //         if (n % 2 == 0)
    //         {
    //             m[n] = 1 + integerReplacement(n / 2);
    //         }
    //         else
    //         {
    //             m[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    //         }
    //     }
    //     return m[n];
    // }

    int integerReplacement(int n)
    {
        return helper(0, n);
    }
    int helper(int step, int n)
    {
        if (n == 1)
            return step;
        if (n % 2 == 0)
        {
            return helper(step + 1, n / 2);
        }
        else
        {
            return min(helper(step + 2, n / 2 + 1), helper(step + 2, n / 2));
        }
    }
};
