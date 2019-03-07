/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (39.65%)
 * Total Accepted:    152.8K
 * Total Submissions: 385.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> b;
        helper(0, res, b, s);
        return res;
    }
    void helper(int pos, vector<vector<string>> &res, vector<string> &ele, string &s)
    {
        if (s.size() == pos)
        {
            res.push_back(ele);
        }
        else
        {
            for (int i = pos + 1; i <= s.size(); i++)
            {
                if (check(pos, i, s))
                {
                    auto tmp = ele;
                    tmp.push_back(s.substr(pos, i - pos));
                    helper(i, res, tmp, s);
                }
            }
        }
    }
    bool check(int ii, int jj, string &s)
    {
        bool res = true;
        for (int i = ii; i < jj; i++)
        {
            res = res && (s[i] == s[jj - 1 - i + ii]);
        }
        return res;
    }
};
