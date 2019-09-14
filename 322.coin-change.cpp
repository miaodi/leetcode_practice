/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (coins.empty())
            return -1;

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto j : coins)
            {
                if (i - j >= 0 && dp[i - j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
