/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (37.25%)
 * Total Accepted:    41.5K
 * Total Submissions: 111.3K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower.
 *
 * However, when you guess a particular number x, and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 *
 * Example:
 *
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = $21.
 *
 *
 * Given a particular n ≥ 1, find out how much money you need to have to
 * guarantee a win.
 */
// similar to split array largest sum
class Solution
{
  public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 1; i <= n; i++)
        {
            dp[0][i - 1] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                int res = INT_MAX;
                for (int k = 0; k <= i; k++)
                {
                    int l = 0, r = 0;
                    if (k != 0)
                    {
                        l = dp[k - 1][j];
                    }
                    if (k != i)
                    {
                        r = dp[i - k - 1][j + k + 1];
                    }
                    res = min(res, max(l, r) + j + k + 1);
                }
                dp[i][j] = res;
            }
        }
        return dp[n - 1][0];
    }
};
