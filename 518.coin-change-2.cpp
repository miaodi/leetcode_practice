/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        vector<long int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto i : coins)
        {
            for (int j = i; j <= amount; j++)
            {
                dp[j] += dp[j - i];
            }
        }
        return dp.back();
    }
};
