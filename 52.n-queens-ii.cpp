/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (51.37%)
 * Total Accepted:    96.4K
 * Total Submissions: 187.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution
{
  public:
    int totalNQueens(int n)
    {
        vector<int> record(n, INT_MAX);
        int res = 0;
        helper(res, record, 0);
        return res;
    }
    void helper(int &res, vector<int> &record, int pos)
    {
        int n = record.size();
        if (pos == n)
        {
            res++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            bool checker = true;
            for (int j = pos - 1; j >= 0; j--)
            {
                if (record[j] == i || record[j] + pos - j == i || record[j] - pos + j == i)
                {
                    checker = false;
                    break;
                }
            }
            if (checker)
            {
                record[pos] = i;
                helper(res, record, pos + 1);
                record[pos] = INT_MAX;
            }
        }
    }
};
