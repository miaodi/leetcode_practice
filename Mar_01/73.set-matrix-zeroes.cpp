/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (38.94%)
 * Total Accepted:    190.5K
 * Total Submissions: 489.1K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
class Solution
{
  public:
//   O(m+n) storage no need for O(1) fucking retard problem
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return;
        int s_x = matrix.size();
        int s_y = matrix[0].size();

        vector<int> x_flag(s_x, 0);
        vector<int> y_flag(s_y, 0);

        for (int i = 0; i < s_x; i++)
        {
            for (int j = 0; j < s_y; j++)
            {
                if (matrix[i][j] == 0)
                {
                    x_flag[i] = 1;
                    y_flag[j] = 1;
                }
            }
        }

        for (int i = 0; i < s_x; i++)
        {
            if (x_flag[i] == 1)
            {
                matrix[i] = vector<int>(s_y, 0);
            }
            else
            {
                for (int j = 0; j < s_y; j++)
                {
                    if (y_flag[j] == 1)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};
