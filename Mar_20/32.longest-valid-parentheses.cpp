/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (25.04%)
 * Total Accepted:    177.1K
 * Total Submissions: 707.3K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        if (s.size() == 0)
            return 0;
        stack<pair<char, int>> st;
        int res = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (st.empty() || st.top().first != '(' || s[i] != ')')
            {
                st.push(make_pair(s[i], i));
            }
            else if (st.top().first == '(' && s[i] == ')')
            {
                st.pop();
            }
        }
        if (st.empty())
            return s.size();
        int e = s.size();
        while (!st.empty())
        {
            res = max(res, e - st.top().second - 1);
            e = st.top().second;
            st.pop();
        }
        res = max(res, e );
        return res;
    }
};
