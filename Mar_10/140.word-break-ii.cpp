/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (26.72%)
 * Total Accepted:    148.9K
 * Total Submissions: 557.2K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 *
 */
class Solution
{

  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        vector<string> res;
        if (s.size() == 0)
            return res;
        vector<bool> dp(s.size() + 1, false);
        unordered_map<int, vector<string>> m;
        dp[0] = true;
        m[0].push_back("");
        for (int i = 0; i < s.size(); i++)
        {
            if (dp[i])
            {
                for (auto &j : wordDict)
                {
                    if (i + j.size() <= s.size() && j == s.substr(i, j.size()))
                    {
                        dp[i + j.size()] = true;

                    } // this or operation is very important.
                }
            }
        }
        if (dp.back() == false)
            return res;
        for (int i = 0; i < s.size(); i++)
        {
            if (dp[i])
            {
                for (auto &j : wordDict)
                {
                    if (i + j.size() <= s.size() && j == s.substr(i, j.size()))
                    {
                        dp[i + j.size()] = true;
                        for (auto &k : m[i])
                        {
                            m[i + j.size()].push_back(k + j + " ");
                        }

                    } // this or operation is very important.
                }
            }
        }

        auto it = m.find(s.size());
        for (auto &i : it->second)
        {
            i.pop_back();
        }
        return it->second;
    }

    // DFS too slow
    void helper(string &s, vector<string> &wordDict, vector<string> &res,
                string &cur, int pos)
    {
        if (pos == s.size())
        {
            cur.pop_back();
            res.push_back(cur);
        }
        for (auto &i : wordDict)
        {
            if (pos + i.size() <= s.size() && i == s.substr(pos, i.size()))
            {
                auto tmp = cur;
                tmp += i;
                tmp.append(" ");
                helper(s, wordDict, res, tmp, pos + i.size());
            }
        }
    }
};
