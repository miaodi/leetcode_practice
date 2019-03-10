/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (32.30%)
 * Total Accepted:    119.4K
 * Total Submissions: 369.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */
class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
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
                    k++;
                }
            }
        }
        return res;
    }
};
