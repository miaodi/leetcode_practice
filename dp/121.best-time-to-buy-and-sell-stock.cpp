/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int m = prices[0];
        int res = 0;
        for (auto i : prices)
        {
            res = max(res, i - m);
            m = min(m, i);
        }
        return res;
    }
};
