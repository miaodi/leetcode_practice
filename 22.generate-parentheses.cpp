/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.57%)
 * Total Accepted:    310.2K
 * Total Submissions: 579.1K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */
class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string s;
        helper(n, res, 0, 0, s);
        return res;
    }

    void helper(int n, vector<string> &res, int l, int r, string &cur)
    {
        if (l + r == 2 * n)
        {
            res.push_back(cur);
        }
        else
        {
            if (l < n)
            {
                auto tmp = cur + '(';
                helper(n, res, l + 1, r, tmp);
            }
            if (l > r)
            {
                auto tmp = cur + ')';
                helper(n, res, l, r + 1, tmp);
            }
        }
    }
    // void helper(int n, vector<string> &res, int l, int r, string &s)
    // {
    //     if (l + r == 2 * n)
    //     {
    //         res.push_back(s);
    //     }
    //     if (l < n)
    //     {
    //         auto tmp = s + "(";
    //         helper(n, res, l + 1, r, tmp);
    //     }
    //     if (r < l)
    //     {
    //         auto tmp = s + ")";
    //         helper(n, res, l, r + 1, tmp);
    //     }
    // }
};
