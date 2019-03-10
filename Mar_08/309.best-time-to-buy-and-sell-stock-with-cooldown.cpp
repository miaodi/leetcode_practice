/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (43.49%)
 * Total Accepted:    83.4K
 * Total Submissions: 191.8K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(2, vector<int>(prices.size()));
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 2 >= 0 ? i - 2 : 0] - prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
        }
        return max(dp[1][prices.size() - 1], dp[1][prices.size() - 2]);
    }
};
