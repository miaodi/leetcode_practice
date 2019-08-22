/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
class Solution
{
    set<int> s;
    template <typename T>
    static T mins(T a, T b)
    {
        return min(a, b);
    }
    template <typename T, typename... Args>
    static T mins(T a, T b, Args... args)
    {
        return min(mins(a, args...), mins(b, args...));
    }

public:
    // TLE
    // int nthUglyNumber(int n)
    // {
    //     if (n == 1)
    //         return 1;
    //     s.insert(1);
    //     int size = 1;
    //     int num = 1;
    //     while (size < n)
    //     {
    //         num++;
    //         if (num % 2 == 0 && s.find(num / 2) != s.end())
    //         {
    //             size++;
    //             s.insert(num);
    //         }
    //         else if (num % 3 == 0 && s.find(num / 3) != s.end())
    //         {
    //             size++;
    //             s.insert(num);
    //         }
    //         else if (num % 5 == 0 && s.find(num / 5) != s.end())
    //         {
    //             size++;
    //             s.insert(num);
    //         }
    //     }
    //     return num;
    // }

    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;
        vector<int> dp;
        dp.reserve(n + 1);
        dp.push_back(1);
        int i = 0, j = 0, k = 0;
        while (dp.size() < n)
        {
            dp.push_back(mins(dp[i] * 2, dp[j] * 3, dp[k] * 5));
            if (dp.back() == dp[i] * 2)
                i++;
            if (dp.back() == dp[j] * 3)
                j++;
            if (dp.back() == dp[k] * 5)
                k++;
        }
        return dp.back();
    }
};
