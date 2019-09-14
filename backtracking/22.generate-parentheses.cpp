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
        helper(n, res, 0, 0, "");
        return res;
    }
    void helper(int n, vector<string> &res, int l, int r, const string &s)
    {
        if (s.size() == 2 * n)
        {
            res.emplace_back(s);
        }
        else
        {
            if (l < n)
            {
                auto tmp = s;
                tmp += "(";
                helper(n, res, l + 1, r, tmp);
            }
            if (l > r)
            {
                auto tmp = s;
                tmp += ")";
                helper(n, res, l, r + 1, tmp);
            }
        }
    }
};
