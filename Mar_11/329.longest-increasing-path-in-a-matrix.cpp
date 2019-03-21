/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 *
 * https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (39.33%)
 * Total Accepted:    79.2K
 * Total Submissions: 201.5K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * Given an integer matrix, find the length of the longest increasing path.
 *
 * From each cell, you can either move to four directions: left, right, up or
 * down. You may NOT move diagonally or move outside of the boundary (i.e.
 * wrap-around is not allowed).
 *
 * Example 1:
 *
 *
 * Input: nums =
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [1, 2, 6, 9].
 *
 *
 * Example 2:
 *
 *
 * Input: nums =
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ]
 * Output: 4
 * Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
 * is not allowed.
 *
 */
class Solution
{
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), -1));
        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                res = max(res, helper(mem, matrix, i, j));
            }
        }
        return res;
    }
    int helper(vector<vector<int>> &mem, vector<vector<int>> &matrix, int i,
               int j)
    {
        if (mem[i][j] != -1)
        {
            return mem[i][j];
        }
        else
        {
            int res = 1;
            if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j])
            {
                res = max(res, helper(mem, matrix, i - 1, j) + 1);
            }
            if (i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j])
            {
                res = max(res, helper(mem, matrix, i + 1, j) + 1);
            }
            if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1])
            {
                res = max(res, helper(mem, matrix, i, j - 1) + 1);
            }
            if (j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j + 1])
            {
                res = max(res, helper(mem, matrix, i, j + 1) + 1);
            }
            mem[i][j] = res;
            return res;
        }
    }
};
