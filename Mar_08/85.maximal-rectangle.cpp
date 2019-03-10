/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (32.45%)
 * Total Accepted:    112.4K
 * Total Submissions: 346.3K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */
class Solution
{
  public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        int s_x = matrix.size();
        int s_y = matrix[0].size();
        vector<vector<int>> dp(s_x + 1, vector<int>(s_y + 1));

        for (int i = 0; i < s_x + 1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j < s_y + 1; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 0; i < s_x; i++)
        {
            for (int j = 0; j < s_y; j++)
            {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] + matrix[i][j] - '0' - dp[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < s_x; i++)
        {
            for (int j = 0; j < s_y; j++)
            {
                int k = 1;
                while (i + k < s_x + 1 && j + k < s_y + 1 && dp[i + k][j + k] + dp[i][j] - dp[i][j + k] - dp[i + k][j] == k * k)
                {
                    res = max(res, k * k);

                    int ki = 1, kj = 1;
                    while (i + k + ki < s_x + 1 && dp[i + ki + k][j + k] + dp[i][j] - dp[i][j + k] - dp[i + ki + k][j] == k * (k + ki))
                    {
                        res = max(res, k * (k + ki));
                        ki++;
                    }
                    while (j + k + kj < s_y + 1 && dp[i + k][j + kj + k] + dp[i][j] - dp[i][j + kj + k] - dp[i + k][j] == k * (k + kj))
                    {
                        res = max(res, k * (k + kj));
                        kj++;
                    }
                    k++;
                }
            }
        }
        return res;
    }
};
