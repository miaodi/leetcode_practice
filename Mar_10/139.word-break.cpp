/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (34.44%)
 * Total Accepted:    306.8K
 * Total Submissions: 890.9K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++)
        {
            for (auto &j : wordDict)
            {
                if (i + j.size() <= s.size() && j == s.substr(i, j.size()))
                {
                    dp[i + j.size()] = dp[i + j.size()] || (dp[i] && true);
                }// this or operation is very important.
            }
        }
        return dp.back();
    }
    // DFS Time Limit Exceeded
    bool helper(string &s, vector<string> &wordDict, int pos)
    {
        if (s.size() == pos)
        {
            return true;
        }
        bool res = false;
        for (auto &i : wordDict)
        {
            if (i == s.substr(pos, i.size()))
            {
                res = res || helper(s, wordDict, pos + i.size());
            }
        }
        return res;
    }
};
