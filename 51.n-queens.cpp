/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (38.58%)
 * Total Accepted:    136.2K
 * Total Submissions: 352.7K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> record(n, INT_MAX);
        vector<vector<string>> res;
        helper(res, record, 0);
        return res;
    }
    void helper(vector<vector<string>> &res, vector<int> &record, int pos)
    {
        int n = record.size();
        if (pos == n)
        {
            res.push_back(vector<string>(n, string(n, '.')));
            for (int i = 0; i < n; i++)
            {
                res.back()[record[i]][i] = 'Q';
            }
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
